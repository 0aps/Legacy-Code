
DWORD EATHook(HMODULE mod,CHAR * FN,VOID* HA,VOID** OA) // Credits: Jimster480 
{ 
    DWORD EATA,OP; 
    IMAGE_DOS_HEADER *DOSH = (IMAGE_DOS_HEADER*)mod; 
    IMAGE_NT_HEADERS *NTH = NULL; 
 
    if(DOSH->e_magic != IMAGE_DOS_SIGNATURE) return NULL; 
 
    NTH = ((PIMAGE_NT_HEADERS)((DWORD)(DOSH) + (DWORD)(DOSH->e_lfanew))); 
 
    if(NTH->Signature != IMAGE_NT_SIGNATURE) return NULL; 
 
    EATA = NTH->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress; 
    IMAGE_EXPORT_DIRECTORY *EATP = (IMAGE_EXPORT_DIRECTORY*) ((DWORD)EATA + (DWORD)mod); 
 
 
    for (DWORD i = 0;i < EATP->NumberOfFunctions;i++) 
    { 
 
        DWORD * ENTP = (DWORD*)((DWORD)mod + ((DWORD)EATP->AddressOfNames + (sizeof(DWORD)*i))); 
 
        if(strcmp((char*)((DWORD)mod + *ENTP),FN)== 0) 
        { 
            WORD * AONP = (WORD*)((DWORD)mod + ((DWORD)EATP->AddressOfNameOrdinals + (i*sizeof(WORD)))); 
            DWORD * AOF  = (DWORD*)((DWORD)mod + ((DWORD)EATP->AddressOfFunctions + (sizeof(DWORD)**AONP))); 
 
            if(!VirtualProtect(AOF,sizeof(DWORD),PAGE_READWRITE,&OP)) return NULL; 
            *OA = (void*)(*AOF+DWORD(mod)); 
            *AOF = (((DWORD)HA)-DWORD(mod)); 
            if(!VirtualProtect(AOF,sizeof(DWORD),OP,&OP)) return NULL; 
            return 1; 
        } 
    } 
    return NULL; 
}

//EATHook(GetModuleHandle("Opengl32.dll"),"glBegin",((VOID*)(&h_glBegin)),((VOID**)(&d_glBegin)));
