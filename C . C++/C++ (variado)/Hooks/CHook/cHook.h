//	CHook - by Darawk 
//	 
//	CHook is a function hooking class, that provides you with 4 different 
//	types of function hooking.  Each type has it's own unique advantages 
//	and disadvantages.  Under different conditions, different hooking 
//	methods are appropriate.  So, i've provided you here with the three 
//	major one's, along with one new one that AFAIK has never been done 
//	(or at least, never published). 
// 
//	1.  Jmp Patch - This method is the most common.  It patches the first 
//		five bytes of the function to be hooked with a relative jump. 
//		However, instead of requiring you to unhook each time you want to 
//		call the original function, CHook uses an LDE(Length Disassembler 
//		Engine) to determine the length of the first few instructions in the 
//		function.  It then copies these instructions out to a buffer, and 
//		appends another relative jump to them.  That relative jump points 
//		just past the relative jump written in by the hook in the hooked 
//		function.  So, when you want to call the original function, you 
//		just call the OriginalFunc() method and it executes this code stub 
//		in order to call the original function without unhooking. 
// 
//	2.	IAT Redirection - The IAT, or Import Address Table when loaded into 
//		memory contains the addresses of each function imported by a given 
//		module(EXE's are included in "modules").  IAT redirection just over- 
//		writes the address of the imported function in the IAT, to point to 
//		the hook.  The downsides of this are that it only works on imported 
//		functions(i.e. not functions that are internal to a module), and it 
//		is module-specific(this could actually be an advantage if you want 
//		your hook to effect only one module). 
// 
//	3.	EAT Redirection - The EAT, or Export Address Table is similar to the 
//		IAT.  Except in the opposite direction.  When a module exports a function 
//		so that it can be used by other modules, it stores the address of  
//		that function in it's EAT.  EAT redirection overwrites that address 
//		with the offset of your hook.  EAT redirection will not effect any 
//		currently loaded modules.  It will only effect modules loaded after the 
//		redirection	has been made.  It will also effect subsequent calls to 
//		GetProcAddress(), as they will return the address of your hook instead of 
//		the real function. 
// 
//	4.	Debug registers - This is the new method that I mentioned above.  All 
//		x86 CPU's have things called debug registers.  These registers are only  
//		directly accessible from privelege level 0(kernel mode).  However, they 
//		can be manipulated using the GetThreadContext/SetThreadContext API's 
//		from privelege level 3(application level).  The intended purpose of the 
//		debug registers is for use by debuggers, in setting breakpoints on memory 
//		access or execution.  Breakpoints generated by the debug registers are 
//		generally called "hardware breakpoints".  Whenever a hardware breakpoint 
//		gets tripped the CPU generates an int-1(single step, same thing as the trap 
//		flag) exception.  So, to hook functions with them, all you need to do is  
//		set the hardware breakpoint on the first byte of the function you want to 
//		hook, and set up an exception handler to catch these exceptions.  The major 
//		advantage of this method, is that these breakpoints will not modify the 
//		process image in any way.  So, a complete checksum of the hooked modules  
//		image will come out perfectly clean.  However, they aren't quite the holy 
//		grail of game hacking.  They do have one major downside.  Which is that 
//		there are only four of them.  Though there are eight actual debug registers, 
//		two of them are unused and two others are used to describe the status of the 
//		other four.  So, it's only possible to simultaneously have four of these  
//		types of hooks set. 
// 
//	This code depends on the mlde32 library by Under-X, available 
//	here: http://vx.netlux.org/vx.php?id=em24 
//	You need to add the mlde32.obj file to your MSVC++ project.  If you use a different compiler 
//	then i'm afraid your on your own as to figuring out how to add the .obj file.  But it shouldn't 
//	be too difficult. 
#pragma once 
 
//	Gotta do this for the vectored exception handling 
#define _WIN32_WINNT 0x0600 
 
#include  
#include  
#include  
#include "types.h" 
 
//	STL namespace 
////////////////////// 
using namespace std; 
 
//	Warnings 
///////////////////// 
// warning C4312: 'type cast' : conversion from  to  of greater size 
#pragma warning(disable : 4312) 
 
 
//	Macros 
////////////////////// 
//	Pietrek's macro 
// 
//	MakePtr is a macro that allows you to easily add to values (including 
//	pointers) together without dealing with C's pointer arithmetic.  It 
//	essentially treats the last two parameters as DWORDs.  The first 
//	parameter is used to typecast the result to the appropriate pointer type. 
#define MakePtr( cast, ptr, addValue ) (cast)( (DWORD_PTR)(ptr) + (DWORD_PTR)(addValue)) 
 
//	This one is mine, but obviously..."adapted" from matt's original idea =p 
#define MakeDelta(cast, x, y) (cast) ( (DWORD_PTR)(x) - (DWORD_PTR)(y)) 
 
//	Constants 
////////////////////// 
#define IMAGE_EXPORT 0 
#define IMAGE_IMPORT 1 
 
#define INSTR_NEAR_PREFIX 0x0F 
#define INSTR_FARJMP 0x2D			//	Far jmp prefixed with INSTR_FAR_PREFIX 
#define INSTR_SHORTJCC_BEGIN 0x70 
#define INSTR_SHORTJCC_END 0x7F 
#define INSTR_NEARJCC_BEGIN 0x80	//	Near's are prefixed with INSTR_NEAR_PREFIX byte 
#define INSTR_NEARJCC_END 0x8F 
#define INSTR_RET 0xC2 
#define INSTR_RETN 0xC3 
#define INSTR_RETFN 0xCA 
#define INSTR_RETF 0xCB 
#define INSTR_INT3 0xCC 
#define INSTR_RELJCX 0xE3 
#define INSTR_RELCALL 0xE8 
#define INSTR_RELJMP 0xE9 
#define INSTR_SHORTJMP 0xEB 
#define INSTR_FAR_PREFIX 0xFF 
 
 
//	External Functions 
///////////////////// 
//	The external LDE engine's function 
extern "C" int __cdecl mlde32(void *codeptr); 
 
//	Structures, enums and typedefs 
///////////////////// 
//	This is a struct to help manage debug register hooks 
typedef struct _DebugHooks 
{ 
	FARPROC targetFuncs[4];		//	There can only be 4 debug hooks set in a given thread at one time 
	FARPROC hookFuncs[4]; 
} DebugHooks, *pDebugHooks; 
 
//	Use these as the CallingConvention argument to the hooking functions 
typedef enum _CallingConventions 
{ 
	Normal,		//	Includes both Stdcall and Cdecl.  I've found a way to 
				//	call a function that will work with either convention. 
	Fastcall, 
	NoRet		//	This is not a documented convention, I don't know what 
				//	it's official name is, if it even has one, so i've named 
				//	it "no ret".  I've only seen it in KiUserExceptionDispatcher 
				//	and the only difference between it and Stdcall is that where 
				//	the return address should be, it has it's first argument. 
} CallingConventions; 
 
//	Various types of hooks 
typedef enum _HookTypes 
{ 
	Patch, 
	IAT, 
	EAT, 
	Debug 
} HookTypes; 
 
//	Class definition 
///////////////////// 
class CHook 
{ 
public: 
 
	//	Con/De-struction 
	//////////////////////// 
	CHook(); 
	~CHook(); 
 
	//	Methods 
	//////////////////////// 
	//	Set a basic patch hook on an Stdcall or Cdecl function 
	bool Hook(FARPROC hookFrom, FARPROC hookTo) { return Hook(hookFrom, hookTo, Normal); }; 
	//	Set a basic patch hook, and explicitly specify the calling convention 
	bool Hook(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv); 
 
	//	Set a hook using a debug register.  This method has one major advantage that none of 
	//	the others can offer, that is if you use a debug register to hook a function, the  
	//	presence of your hook will not be visible to any type of memory scanning.  The 
	//	downside of using debug registers is that you can only have for of them at any given 
	//	time, for reasons explained above. 
	bool DebugHook(FARPROC hookFrom, FARPROC hookTo) { return DebugHook(hookFrom, hookTo, Normal); }; 
	bool DebugHook(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv); 
 
	//	Hook the IAT(Import Address Table) of a specific module(this includes the .exe file) 
	bool HookIAT(FARPROC hookFrom, FARPROC hookTo, HMODULE target) { return HookIAT(hookFrom, hookTo, target, Normal); }; 
	bool HookIAT(FARPROC hookFrom, FARPROC hookTo, HMODULE target, CallingConventions cconv); 
 
	//	Hook the EAT(Export Address Table) of a module in this process image.  This will cause all 
	//	subsequent calls to GetProcAddress on the function you're hooking to return the address of 
	//	your hook, instead of the real function.  It will also cause all subsequently loaded modules 
	//	to import your hook instead of the real function.  However, it will not effect any currently 
	//	loaded modules. 
	bool HookEAT(FARPROC hookFrom, FARPROC hookTo) { return HookEAT(hookFrom, hookTo, Normal); }; 
	bool HookEAT(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv); 
 
	//	Remove a hook 
	bool Unhook(); 
 
	//	Enable/disable a hook temporarily 
	//	NOTE: These ONLY apply to hooks created with the Hook() 
	//	function. 
	bool Enable(); 
	bool Disable(); 
 
    //	Call this to call the original function, without the hook 
	u32 OriginalFunc(u32 num, ...); 
 
	//	Accessors 
	///////////////////////// 
	//	Find out if a function is hooked in this instance or not. 
	bool IsHooked() const { return bHooked; }; 
	//	Get the type of hook 
	HookTypes GetType() const { return type; }; 
	//	Get the calling convention 
	CallingConventions GetCallingConvention() const { return convention; }; 
	//	Get the target of this hook 
	FARPROC GetTarget() const { return m_hookFrom; }; 
	//	Get the function that the target is redirected to 
	FARPROC GetHookFunc() const { return m_hookTo; }; 
	//	Check if the hook is currently enabled.  Applies only to hooks created 
	//	with Hook(). 
	bool IsEnabled() const { return bEnabled; } 
 
private: 
	FARPROC m_hookFrom, m_hookTo; 
	HMODULE m_target; 
	u8 entryStub[256], oldbytes[32], patchbytes[32]; 
	u32 stubLen; 
	CallingConventions convention;	//	Default to Stdcall 
	HookTypes type;					//	Indicates the type of hook that is currently installed. 
	bool bHooked;					//	Indicates whether or not a function is currently hooked 
									//	in this instance of the class. 
	bool bEnabled; 
 
	//	PE Header structures 
	//////////////////////////// 
	IMAGE_DOS_HEADER *dosHd; 
	IMAGE_NT_HEADERS *ntHd; 
 
	//	Static data 
	/////////////////////////// 
	static bool debugInitialized; 
	static DebugHooks debugHooks; 
	static CHook *threadHook; 
	static map int3hooks; 
 
	//	Private methods 
	/////////////////////////// 
	//	Build the code stub that will be called by OriginalFunc() 
	bool BuildStub(); 
	//	Functions to patch code for hooking 
	static void WriteJump(void *from, void *to); 
	static void WriteInt3(void *at); 
 
	//	Inserts an instruction into the code stub 
	u32 InsertInstruction(u8 *intptr); 
	u32 InsertBranch(u8 branchType, void *to); 
 
	//	Check to see if an instruction is a ret/retn 
	static bool IsRet(u8 *instr); 
 
	//	Manipulation of the debug registers, these set/clear the 
	//	debug register in a given thread. 
	static int SetDebugBreak(FARPROC address); 
	static bool ClearDebugBreak(u32 index); 
 
	static LONG CALLBACK DebugHookHandler(PEXCEPTION_POINTERS ExceptionInfo); 
    static LONG CALLBACK Int3HookHandler(PEXCEPTION_POINTERS ExceptionInfo); 
	static u32 ThreadCallback(); 
 
	IMAGE_SECTION_HEADER *GetEnclosingSectionHeader(u32 rva); 
	unsigned long GetMappedSectionOffset(IMAGE_SECTION_HEADER *seHd); 
	void *GetPtrFromRVA(u32 rva, bool mapped); 
};
