#define _WIN32_WINNT 0x0500
#include <windows.h>

#include <gl/gl.h>
#include <gl/glu.h>
 
typedef void (WINAPI *TGLUI)(GLuint);
typedef void (WINAPI *TGLED)(GLenum);
TGLUI pglBegin;TGLED pglEnable,pglDisable;
 
typedef void (WINAPI *TGFV)(GLenum,GLfloat *);
typedef void (WINAPI *TV3FV)(const GLfloat *v);
 
BOOL bSmoke=FALSE,bFlash=FALSE;TGFV pglGetFloatv;TV3FV pglVertex3fv;
 
typedef void (WINAPI *TC3F)(GLfloat,GLfloat,GLfloat);
typedef void (WINAPI *TC4F)(GLfloat,GLfloat,GLfloat,GLfloat);
typedef void (WINAPI *TV2F)(GLfloat,GLfloat);
typedef void (WINAPI *TC)(GLbitfield);
typedef void (WINAPI *TCC)(GLclampf,GLclampf,GLclampf,GLclampf);
typedef void (WINAPI *TTE)(GLenum,GLenum,GLfloat);
 
TV2F pglVertex2f;TC3F pglColor3f;TC4F pglColor4f;
TC pglClear;TCC pglClearColor;TTE pglTexEnvi;
 
void DPrint(char *frmt,...){
  static char tmp[1024];va_list p;
  va_start(p,frmt);
  wvsprintf(tmp,frmt,p);
  va_end(p);
  OutputDebugString(tmp);
}
 
void WINAPI hglBegin(GLenum mode){
  if((mode==GL_TRIANGLE_STRIP)||mode==GL_TRIANGLE_FAN){
    pglDisable(GL_DEPTH_TEST);
    pglEnable(GL_BLEND);
  }
  if(mode==GL_QUADS){
    float col[4];
		pglGetFloatv(GL_CURRENT_COLOR, col);
    bSmoke = (col[0] == col[1] && col[0] == col[2] && col[0] != 0.0 && col[0] != 1.0);
		bFlash = (col[0] == 1.0 && col[1] == 1.0 && col[2] == 1.0 && col[3] > 0.2);
  }
  if(mode == GL_TRIANGLE_STRIP || mode == GL_TRIANGLE_FAN)
		pglTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  pglBegin(mode);
}
 
void WINAPI hglVertex3fv(const GLfloat *v){
	if(bSmoke)return;
	pglVertex3fv(v);
}
 
void WINAPI hglVertex2f(GLfloat x, GLfloat y){
  if(bFlash==TRUE&&x==0.0&&y==0.0)
		pglColor4f(1.0f, 1.0f, 1.0f, 0.2f);
	pglVertex2f(x, y);
}
 
void WINAPI hglClear(GLbitfield mask){
  if (mask == GL_DEPTH_BUFFER_BIT){
    mask+=GL_COLOR_BUFFER_BIT;
    pglClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
	pglClear(mask);
}
 
//api hooking aqui.
//detour = desvio

void *DetourFunc(BYTE *src, const BYTE *dst, const int len){
  BYTE *jmp = (BYTE*)malloc(len+5);
  DWORD dwback;
  while(!VirtualProtect(src, len, PAGE_READWRITE, &dwback));
  memcpy(jmp, src, len);jmp+=len;
  
  jmp[0] = 0xE9;
  //salto hacia la continuacion de la api
  *(DWORD*)(jmp+1)=(DWORD)(src+len-jmp)-5;
  
  src[0] = 0xE9;
  //salto hacia mi funcion
  *(DWORD*)(src+1)=(DWORD)(dst-src)-5;
  while(!VirtualProtect(src, len, dwback, &dwback));
  
  //devuelvo el principio del buffer
  //en el buffer se ejecutan los bytes de la api 
  //y luego se hace el salto hacia la api normal
  return (jmp-len);
}
 
//anti-anti-wallhack... by cocodrilo
void __stdcall aawh(void);
asm(
  ".globl _aawh\r\n"
  "_aawh:\r\n"
  "  movl $1, (%eax);\r\n"
  "  ret;"
);
 
DWORD WINAPI HookOpenGl(LPVOID lpParam){
  HWND hdHalfLife;DWORD dwThreadId;DWORD dwProcessId;
  CONTEXT Context;LDT_ENTRY SelEntry;
  
  //devuelve la estructura del contexto completa ademas
  //el debug de los registros que no se encuentra incluida en el context full
  Context.ContextFlags=CONTEXT_FULL|CONTEXT_DEBUG_REGISTERS;
 
   while(
    ((hdHalfLife=FindWindow("Valve001",NULL))==NULL)&&
    ((hdHalfLife=FindWindow(NULL,"Counter-Strike"))==NULL)
  )Sleep(10);
 
  dwThreadId=GetWindowThreadProcessId(hdHalfLife,&dwProcessId);
 
  HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwProcessId);
  HANDLE hThread=OpenThread(THREAD_ALL_ACCESS,FALSE,dwThreadId);
 
  //suspendo lo que se este haciendo en el proceso/hilo
  SuspendThread(hThread);
  
  //obtengo el contex del hilo
  GetThreadContext(hThread,&Context);
  
  //Context.SegFs apunta al segmento de datos (FS) 
  //la funcion devuelve una copia (a selEntry) de la tabla de entrada del descriptor especificado
  GetThreadSelectorEntry(hThread, Context.SegFs, &SelEntry);
  ResumeThread(hThread);
  
  //BaseHi son los bits mas alto del segmento 
  // en este fcaso FS  
  //BaseMid son los bits de medio 
  //BaseLow The low-order part of the base address of the segment.
  
  PVOID dwFSBase = (PVOID)((SelEntry.HighWord.Bits.BaseHi<<24)|
    (SelEntry.HighWord.Bits.BaseMid<<16)|SelEntry.BaseLow);
 
  //multiple redirect...
  PVOID dwFSBase2=(PVOID)(*(PDWORD)( (DWORD)dwFSBase + (* (PDWORD)0x5F1CC80C) ) );
 
  // 0x01D93500 opengl32.glDisable [EAX+994] -> 0x69609E40
  pglDisable=(TGLED)(*(PDWORD)(dwFSBase+0x994));
  // 0x01D35598 opengl32.glEnable [EAX+998] -> 0x69609EA0
  pglEnable=(TGLED)(*(PDWORD)(dwFSBase+0x998));
  // 0x01D46719  opengl32.glGetFloatv [EAX+418] -> 0x6960B040
  pglGetFloatv=(TGFV)(*(PDWORD)(dwFSBase2+0x418));
  // 0x01D492C9  opengl32.glColor3f [EAX+7E0] -> 0x695FDCA0
  pglColor3f=(TC3F)( *(PDWORD)(dwFSBase+0x7E0) );
  // 0x01D3CEDB  opengl32.glColor4f [EAX+820] -> 0x695FF2C0
  pglColor4f=(TC4F)(*(PDWORD)(dwFSBase+0x820));
  // 0x01D46F04  opengl32.glClearColor [EAX+338] -> 0x69609B40
  pglClearColor=(TCC)(*(PDWORD)(dwFSBase2+0x338));
  // 0x01D44A1C  opengl32.glTexEnvi [EAX+2E8] -> 0x696093C0
  pglTexEnvi=(TTE)(*(PDWORD)(dwFSBase2+0x2E8));
 
  SuspendThread(hThread);
  
  // 0x01D46862  opengl32.glClear [EAX+32C] -> 0x69609A20 [12]
  pglClear=(TC)DetourFunc( (PBYTE)( *(PDWORD)(dwFSBase2+0x32C) ),(PBYTE)hglClear,12);
  
  // 0x01D3CF1D  opengl32.glVertex2f [EAX+92C] -> 0x69606320 [12]
  pglVertex2f=(TV2F)DetourFunc((PBYTE)(*(PDWORD)(dwFSBase+0x92C)),(PBYTE)hglVertex2f,12);
  // 0x01D936C5 opengl32.glVertex3fv [EAX+950] -> 0x696073F0 [12]
  pglVertex3fv=(TV3FV)DetourFunc((PBYTE)(*(PDWORD)(dwFSBase+0x950)),(PBYTE)hglVertex3fv,12);
  
  // 0x01D93681 opengl32.glBegin [EAX+7CC] -> 0x695FD250 [8]
  pglBegin=(TGLUI)DetourFunc((PBYTE)(*(PDWORD)(dwFSBase+0x7CC)),(PBYTE)hglBegin,8);
  
  //anti-anti-wallhack... by cocodrilo
  *( (PDWORD)0x01ECD4CC ) = (DWORD)aawh;
  
  ResumeThread(hThread);
 
  CloseHandle(hThread);
  CloseHandle(hProcess);
  return 0;
}
 
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved){
  switch (fdwReason){
    case DLL_PROCESS_ATTACH:
      CreateThread(NULL, 0, HookOpenGl, NULL, 0, NULL);
    break;
    case DLL_PROCESS_DETACH:break;
  }
  return TRUE;
}
