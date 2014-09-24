#include "CHook.h"   
#include <conio.h>   
//  Initialize static members   
/////////////////////////   
bool CHook::debugInitialized = false;   
DebugHooks CHook::debugHooks;   
CHook *CHook::threadHook;   
map<farproc, farproc=""> CHook::int3hooks;   
   
   
//  Constructor   
CHook::CHook()   
{   
    m_hookFrom = NULL;   
    m_hookTo = NULL;   
    m_target = NULL;   
    memset(entryStub, 0, sizeof(entryStub));   
    bHooked = false;   
    stubLen = 0;   
   
    if(!debugInitialized)   
    {     
        //AddVectoredExceptionHandler(0, (PVECTORED_EXCEPTION_HANDLER)Int3HookHandler);   
        AddVectoredExceptionHandler(0, (PVECTORED_EXCEPTION_HANDLER)DebugHookHandler);   
        debugInitialized = true;   
        //threadHook = new CHook;   
        //threadHook->Hook(GetProcAddress(GetModuleHandle("ntdll.dll"), "CsrNewThread"), (FARPROC)ThreadCallback);   
   
    }   
}   
   
//  Destructor   
CHook::~CHook()   
{   
    //  Remove any hooks we may have   
    Unhook();   
}   
   
//  Hook a function   
bool CHook::Hook(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv)   
{   
    //  Make sure we got valid function pointers, and that a function   
    //  isn't currently being hooked by this instance of CHook.   
    if(IsBadReadPtr(hookFrom, 5) || IsBadReadPtr(hookTo, 1) || bHooked)   
        return false;   
   
    m_hookFrom = hookFrom;   
    m_hookTo = hookTo;   
   
    //  Save the first 5 bytes, which could get over-written   
    memcpy(oldbytes, m_hookFrom, 5);   
         
    if(BuildStub()){   
        //WriteJump(m_hookFrom, m_hookTo);   
    }else   
    {   
        WriteInt3(m_hookFrom);   
        int3hooks[m_hookFrom] = m_hookTo;   
    }   
   
    //  Store all the necessary data about this hook   
    memcpy(patchbytes, m_hookFrom, 5);   
    convention = cconv;   
    bHooked = true;   
    type = Patch;   
    bEnabled = true;   
       
    return true;   
}   
   
bool CHook::DebugHook(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv)   
{   
    if(bHooked){   
        return false;   
    }   
   
   
    s32 i = SetDebugBreak(hookFrom);   
   
    _cprintf("idr %d\n",i);   
   
    if(i == -1)   
        return false;   
    debugHooks.targetFuncs[i] = hookFrom;   
    debugHooks.hookFuncs[i] = hookTo;   
   
    //  Build a call stub   
    //u32 len = mlde32(MakePtr(void *, hookFrom, 0));   
   
    //memset(entryStub, 0, sizeof(entryStub));   
    //memcpy(entryStub, MakePtr(void *, hookFrom, 0), len);   
   
    //u8 relJmp[] = {INSTR_RELJMP, 0x00, 0x00, 0x00, 0x00};   
    //*(u32 *)(relJmp + 1) = MakeDelta(u32, hookFrom, entryStub) - 5;   
    //memcpy(&entryStub[len], relJmp, sizeof(relJmp));   
   
    //stubLen = len + sizeof(relJmp);   
    m_hookFrom = hookFrom;   
    m_hookTo = hookTo;   
    convention = cconv;   
    type = Debug;   
    bHooked = true;   
   
    _cprintf("hookFrom 0x%08X hookTo 0x%08X \n",hookFrom,hookTo);   
   
   
    return true;   
}   
   
//  Hook the IAT of a specific module(this includes the .exe file)   
bool CHook::HookIAT(FARPROC hookFrom, FARPROC hookTo, HMODULE target, CallingConventions cconv)   
{   
   
    if(bHooked)   
        return false;   
   
    dosHd = (IMAGE_DOS_HEADER *)target;   
    ntHd = MakePtr(IMAGE_NT_HEADERS *, target, dosHd->e_lfanew);   
   
    IMAGE_IMPORT_DESCRIPTOR *impDesc = (IMAGE_IMPORT_DESCRIPTOR *)GetPtrFromRVA(ntHd->OptionalHeader.DataDirectory[IMAGE_IMPORT].VirtualAddress, true);   
   
    if(!(impDesc->Name))   
        return false;   
   
    IMAGE_THUNK_DATA *thunk = (IMAGE_THUNK_DATA *)GetPtrFromRVA(impDesc->FirstThunk, true);   
           
    while(impDesc->Name)   
    {   
        thunk = MakePtr(IMAGE_THUNK_DATA *, target, impDesc->FirstThunk);   
   
        while(thunk->u1.Function && thunk->u1.Function != MakePtr(u32, hookFrom, 0))   
            thunk++;   
   
        if(thunk->u1.Function == MakePtr(u32, hookFrom, 0))   
            break;   
   
        impDesc++;   
    }   
   
    if(impDesc->Name && thunk->u1.Function)   
    {   
        u32 oldprot, oldprot2;   
        VirtualProtect(&(thunk->u1.Function), sizeof(u32), PAGE_READWRITE, (DWORD *)&oldprot);   
        thunk->u1.Function = MakePtr(u32, hookTo, 0);   
        VirtualProtect(&(thunk->u1.Function), sizeof(u32), oldprot, (DWORD *)&oldprot2);   
    }   
    else   
        return false;   
   
    convention = cconv;   
    m_hookFrom = hookFrom;   
    m_hookTo = hookTo;   
    m_target = target;   
    bHooked = true;   
    type = IAT;   
    return true;   
}   
   
   
bool CHook::HookEAT(FARPROC hookFrom, FARPROC hookTo, CallingConventions cconv)   
{   
    if(bHooked)   
        return false;   
   
    HMODULE target;   
    if(!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)hookFrom, &target))   
        return false;   
   
   
    dosHd = (IMAGE_DOS_HEADER *)target;   
    ntHd = MakePtr(IMAGE_NT_HEADERS *, target, dosHd->e_lfanew);   
    IMAGE_EXPORT_DIRECTORY *ied = (IMAGE_EXPORT_DIRECTORY *)GetPtrFromRVA(ntHd->OptionalHeader.DataDirectory[IMAGE_EXPORT].VirtualAddress, true);   
   
    FARPROC *funcs = (FARPROC *)GetPtrFromRVA(ied->AddressOfFunctions, true);   
   
    u32 i;   
    for(i = 0; i < ied->NumberOfFunctions; i++)   
        if(MakePtr(FARPROC, target, funcs[i]) == hookFrom)   
            break;   
   
    if(i >= ied->NumberOfFunctions)   
        return false;   
   
    u32 oldprot, oldprot2;   
    VirtualProtect(&funcs[i], sizeof(u32), PAGE_READWRITE, (DWORD *)&oldprot);   
    funcs[i] = MakeDelta(FARPROC, hookTo, target);   
    VirtualProtect(&funcs[i], sizeof(u32), oldprot, (DWORD *)&oldprot2);   
   
    convention = cconv;   
    m_hookFrom = hookFrom;   
    m_hookTo = hookTo;   
    m_target = target;   
    bHooked = true;   
    type = EAT;   
    return true;   
}   
   
//  Unhook a function   
bool CHook::Unhook()   
{   
    //  Make sure we are actually currently hooking something before   
    //  trying to unhook.   
    if(!bHooked)   
        return false;   
   
    switch(type)   
    {   
    case Patch:   
        //  Remove the relative jump from the entry point   
        //  of the hooked function.   
        u32 oldprot, oldprot2;   
        VirtualProtect(m_hookFrom, 5, PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
        memcpy(m_hookFrom, oldbytes, 5);   
        VirtualProtect(m_hookFrom, 5, oldprot, (DWORD *)&oldprot2);   
   
        //  Clear the code stub   
        memset(entryStub, 0, sizeof(entryStub));   
        memset(oldbytes, 0, sizeof(oldbytes));   
   
        if(int3hooks[m_hookFrom])   
            int3hooks.erase(m_hookFrom);   
   
        //  This class is no longer hooking a function   
        bHooked = false;   
        break;   
    case IAT:   
        //  Essentially, just hook it all back the opposite way   
        if(HookIAT(m_hookTo, m_hookFrom, m_target, convention))   
            bHooked = false;   
        else   
            bHooked = true;   
        break;   
    case EAT:   
        //  Same as above, just reverse it   
        bHooked = false;   
        if(HookEAT(m_hookTo, m_hookFrom, convention))   
            m_target = NULL;   
        else   
            bHooked = true;   
        break;   
    case Debug:   
        memset(entryStub, 0, sizeof(entryStub));   
        stubLen = 0;   
   
        u32 i;   
        for(i = 0; debugHooks.targetFuncs[i] != m_hookFrom; i++);   
           
        _cprintf("clear reg dr%d targetFuncs 0x%08x m_hookFrom 0x%08X m_hookTo 0x%08X\n",i,debugHooks.targetFuncs[i],m_hookFrom,m_hookTo);   
        debugHooks.targetFuncs[i] = 0;   
        debugHooks.hookFuncs[i] = 0;   
        if (ClearDebugBreak(i))   
          bHooked = false;   
        break;   
    default:   
        //  ?   
        break;   
    }   
       
    stubLen = 0;   
    if(!bHooked)   
        return true;   
   
    return false;   
}   
   
bool CHook::Enable()   
{   
    if(bEnabled && type != Patch)   
        return false;   
   
    u32 oldprot, oldprot2;   
    VirtualProtect(m_hookFrom, 5, PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
    memcpy(m_hookFrom, patchbytes, 5);   
    VirtualProtect(m_hookFrom, 5, oldprot, (DWORD *)&oldprot2);   
    bEnabled = true;   
    return true;   
}   
   
bool CHook::Disable()   
{   
    if(!bEnabled && type != Patch)   
        return false;   
   
    u32 oldprot, oldprot2;   
    VirtualProtect(m_hookFrom, 5, PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
    memcpy(m_hookFrom, oldbytes, 5);   
    VirtualProtect(m_hookFrom, 5, oldprot, (DWORD *)&oldprot2);   
    bEnabled = false;   
    return true;   
}   
   
   
u32 CHook::OriginalFunc(u32 num, ...)   
{   
    u32 retVal;   
   
    if(!bHooked)   
        return 0;   
   
    u32 *argArray = NULL;   
    if(num)   
    {   
        va_list args;   
        va_start(args, num);   
       
        argArray = new u32[num];   
   
        for(u32 i = 0; i < num; i++)   
            argArray[i] = va_arg(args, u32);   
   
        //  Push the arguments onto the stack   
        _asm   
        {   
            mov ecx, num   
    loop1:   
            dec ecx   
            mov eax, argArray   
            mov ebx, [eax + ecx * 4]   
            push ebx   
            test ecx, ecx   
            jnz loop1   
        }   
   
        va_end(args);   
    }   
   
    FARPROC tmp;   
    switch(type)   
    {   
    //  Debug hooks are called in exactly the same way as patch's   
    case Debug:   
        tmp = MakePtr(FARPROC, entryStub, 0);   
        break;   
    case Patch:   
        tmp = MakePtr(FARPROC, entryStub, 0);   
        break;   
    //  IAT/EAT hooks are the same for this part   
    case IAT:   
    case EAT:   
        tmp = m_hookFrom;   
        break;   
    default:    
        // ?   
        break;   
    }   
   
   
    //  Call it based on the calling convention specified by the user   
    switch(convention)   
    {   
    //  Properties of Normal:   
    //      Arguments are pushed onto the stack from left to right   
    //      Caller restores ESP after the function exits   
    //         
    //      NOTE: Normal is not a real calling convention.  It's my   
    //      combination of Stdcall and Cdecl.  It simply restores ESP   
    //      regardless of whether or not the callee already did so.   
    case Normal:   
        _asm   
        {   
            mov ecx, num   
            lea ecx, [ecx * 4]   
            xor ebx, ebx   
            add ebx, ecx   
            add ebx, esp    //  Calculate the value of esp before args were pushed, and store   
                            //  it in ebx   
            mov eax, tmp   
            call eax   
            mov retVal, eax   
            mov esp, ebx    //  Restore esp   
        }   
        break;   
    //  Properties of Fastcall:   
    //      First two arguments are passed in ecx and edx   
    //         
    case Fastcall:   
        _asm   
        {   
            mov eax, argArray   
            mov ecx, [eax]   
            mov edx, [eax + 4]   
            add esp, 8          //  Get rid of the first 2 args that we pushed earlier   
            mov eax, tmp   
            call eax   
            mov retVal, eax   
            add esp, 8   
        }   
        break;   
    //  Properties of NoRet:   
    //      Takes first argument where the return address should be   
    //      Function does not return   
    case NoRet:   
        _asm   
        {   
            mov eax, tmp   
            jmp eax   
        }   
        break;   
    default:   
        retVal = 0;   
        break;   
    }   
   
    if(argArray)   
        delete argArray;   
   
    return retVal;   
}   
   
   
//  Private methods   
///////////////////////////   
bool CHook::BuildStub()   
{   
    u32 len;   
    u8 *codeptr = (u8 *)m_hookFrom;   
    bool retval = true;   
    //  Set the memory page of the entry stub to executable, so we can jump to it.   
    u32 oldprot;   
    VirtualProtect(entryStub, sizeof(entryStub), PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
    for(u32 len = 0, instrLen = 0; len < 5; instrLen = InsertInstruction(codeptr))   
    {   
        if(IsRet(codeptr))   
            retval = false;   
        codeptr += instrLen;   
        len += instrLen;   
    }   
    stubLen += len;   
    stubLen += InsertBranch(INSTR_RELJMP, MakeDelta(void *, m_hookFrom, 5));   
    return retval;   
}   
   
void CHook::WriteJump(void *from, void *to)   
{   
    u32 oldprot;   
    u8 relJmp[] = {INSTR_RELJMP, 0, 0, 0, 0};   
   
    VirtualProtect(from, sizeof(relJmp), PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
    //  Build the relative jump that will be patched onto from   
    u32 offset = MakeDelta(u32, to, from) - 5;   
    //  Build the relative jump   
    *(u32 *)(relJmp + 1) = offset;   
    memcpy(from, relJmp, sizeof(relJmp));   
    //  If this one fails, it won't effect the operation of the hook.   
    //  So, I don't think it's necessary for Hook() to fail if this   
    //  VirtualProtect() does.   
    u32 oldprot2;   
    VirtualProtect(from, sizeof(relJmp), oldprot, (DWORD *)&oldprot2);   
    //  Flush the CPU's instruction cache.  This should always be done   
    //  when writing self-modifying code, because the CPU will cache   
    //  instructions, and may not detect our newly modified code.   
    FlushInstructionCache(GetCurrentProcess(), NULL, 0);   
}   
   
void CHook::WriteInt3(void *at)   
{   
    u32 oldprot;   
    VirtualProtect(at, 1, PAGE_EXECUTE_READWRITE, (DWORD *)&oldprot);   
    *(u8 *)at = INSTR_INT3;   
    u32 oldprot2;   
    VirtualProtect(at, 1, oldprot, (DWORD *)&oldprot2);   
    FlushInstructionCache(GetCurrentProcess(), NULL, 0);   
}   
   
u32 CHook::InsertInstruction(u8 *codeptr)   
{   
    //  This code will determine what type of branch it is, and   
    //  increment the pointer to point to the relative branch's   
    //  offset.  This has to be modified in the same way for every   
    //  instruction.   
    s32 offset = 0;   
    u8 opcode = *codeptr;   
    switch(*codeptr)   
    {   
    case INSTR_SHORTJMP:   
        //  Short offset values are only 1 byte long, and they are signed   
        offset = *(s8 *)(codeptr + 1);   
        offset = MakePtr(s32, codeptr, offset);   
        break;   
    case INSTR_RELJCX:   
    case INSTR_RELCALL:   
    case INSTR_RELJMP:   
        //  Near jmps have only a 1 byte opcode   
        offset = *MakePtr(s32 *, codeptr, 1);   
        offset = MakePtr(s32, codeptr, offset);   
        break;   
    case INSTR_NEAR_PREFIX:   
        //  Near conditional jumps have a 2 byte opcode   
        offset = *MakePtr(s32 *, codeptr, 2);   
        offset = MakePtr(s32, codeptr, offset);   
        opcode = *(codeptr + 1);   
        break;   
    case INSTR_INT3:   
        //  An int03 instruction could be one of our hooks.  If it is, then we need   
        //  to turn it into a jump instruction for the stub.   
        offset = MakePtr(u32, int3hooks[MakePtr(FARPROC, codeptr, 0)], 0);   
        opcode = INSTR_RELJMP;   
   
        //  Check to see if this is one of our int3 hooks   
        if(!offset)   
        {   
            entryStub[stubLen] = INSTR_INT3;   
            return 1;   
        }   
        break;   
    default:   
        //  Check to see if it's in the valid range of JCC values.   
        //  e.g. ja, je, jne, jb, etc..   
        if(*codeptr >= INSTR_SHORTJCC_BEGIN && *codeptr <= INSTR_SHORTJCC_END)   
        {   
            offset = *(s8 *)(codeptr + 1);   
            offset = MakePtr(s32, codeptr, offset);   
            //  Convert it to a NEAR condition code   
            opcode += INSTR_NEARJCC_BEGIN - INSTR_SHORTJCC_BEGIN;   
        }   
        else   
        {   
            //  Non-Branching, non-int3 instruction   
            memcpy(&entryStub[stubLen], codeptr, mlde32(codeptr));   
            return mlde32(&entryStub[stubLen]);   
        }   
    }   
   
    return InsertBranch(opcode, (void *)offset);   
}   
   
u32 CHook::InsertBranch(u8 branchType, void *to)   
{   
    u8 *instr = &entryStub[stubLen];   
    if(branchType != INSTR_RELJMP && branchType != INSTR_RELCALL && branchType != INSTR_RELJCX)   
    {   
        *instr = INSTR_NEAR_PREFIX;   
        ++instr;   
    }   
    *instr = branchType;   
    ++instr;   
    *(u32 *)instr = MakeDelta(u32, &entryStub[stubLen], to) - mlde32(&entryStub[stubLen]);   
    return mlde32(&entryStub[stubLen]);   
}   
   
bool CHook::IsRet(u8 *instr)   
{   
    switch(*instr)   
    {   
        case INSTR_RET:   
        case INSTR_RETN:   
        case INSTR_RETFN:   
        case INSTR_RETF:   
            return true;   
    }   
   
    return false;   
}   
   
int CHook::SetDebugBreak(FARPROC address)   
{   
    u32 retval=-1;   
    HANDLE thSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);   
    THREADENTRY32 te;   
    te.dwSize = sizeof(THREADENTRY32);   
   
    Thread32First(thSnap, &te);   
    do   
    {     
       
        if(te.th32OwnerProcessID != GetCurrentProcessId())   
            continue;   
        HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);   
        CONTEXT ctx;   
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;   
        GetThreadContext(hThread, &ctx);   
         //_cprintf("set  threadID %d source Dr7=0x%08X \n",te.th32ThreadID,ctx.Dr7);   
        if(!ctx.Dr0)   
        {   
            ctx.Dr0 = MakePtr(u32, address, 0);   
            ctx.Dr7 |= 0x00000001;     
            retval = 0;   
        }   
        else if(!ctx.Dr1)   
        {   
            ctx.Dr1 = MakePtr(u32, address, 0);   
            //ctx.Dr7 |= 0x00000002;   
                ctx.Dr7 |= 0x00000004;   
            retval = 1;   
        }   
        else if(!ctx.Dr2)   
        {   
            ctx.Dr2 = MakePtr(u32, address, 0);   
          //   ctx.Dr7 |= 0x00000004;   
            ctx.Dr7 |= 0x00000010;   
            retval = 2;   
        }   
        else if(!ctx.Dr3)   
        {   
            ctx.Dr3 = MakePtr(u32, address, 0);   
        //  ctx.Dr7 |= 0x00000008;   
            ctx.Dr7 |= 0x00000040;   
            retval = 3;   
        }   
        else   
            retval = -1;   
         
        //_cprintf("set threadID %d  target Dr7=0x%08X \n",te.th32ThreadID,ctx.Dr7);   
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;   
        SetThreadContext(hThread, &ctx);   
        CloseHandle(hThread);   
    } while(Thread32Next(thSnap, &te));   
   
    return retval;   
}   
   
bool CHook::ClearDebugBreak(u32 index)   
{   
    HANDLE thSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);   
    THREADENTRY32 te;   
    te.dwSize = sizeof(THREADENTRY32);   
   
    Thread32First(thSnap, &te);   
   
    do   
    {   
        if(te.th32OwnerProcessID != GetCurrentProcessId())   
            continue;   
   
        HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);   
        CONTEXT ctx;   
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;   
        GetThreadContext(hThread, &ctx);   
        //_cprintf("clear idx%d  threadID %d source Dr0 0x%08X  Dr7 0x%08X\n",index,te.th32ThreadID,ctx.Dr0,ctx.Dr7);   
   
        switch(index)   
        {   
   
        case 0:   
            ctx.Dr0 = 0;   
            ctx.Dr7 &= 0xFFF0FFFE;  //  Clear the 16-19th and 1st bits   
           
            break;   
        case 1:   
            ctx.Dr1 = 0;   
        //  ctx.Dr7 &= 0xFF0FFFFD;  //  Clear the 20-23rd and 2nd bits   
            ctx.Dr7 &= 0xFF0FFFFB;   
           
            break;   
        case 2:   
            ctx.Dr2 = 0;   
            //ctx.Dr7 &= 0xF0FFFFFB;    //  Clear the 24-27th and 3rd bits   
            ctx.Dr7 &=0xF0FFFFEF;   
                         
            break;   
        case 3:   
            ctx.Dr3 = 0;   
            //ctx.Dr7 &= 0x0FFFFFF7;    //  Clear the 28-31st and 4th bits   
            ctx.Dr7 &=0xFFFFFBF;   
            break;   
        default:   
            return false;   
        }   
        //_cprintf("clear idx%d  threadID %d source Dr0 0x%08X  Dr7 0x%08X\n",index,te.th32ThreadID,ctx.Dr0,ctx.Dr7);   
        SetThreadContext(hThread, &ctx);   
        CloseHandle(hThread);   
    } while(Thread32Next(thSnap, &te));   
   
    return true;   
}   
   
LONG CALLBACK CHook::DebugHookHandler(PEXCEPTION_POINTERS ExceptionInfo)   
{   
   
    if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_SINGLE_STEP)   
    {      
        u32 i;   
        for(i = 0; i < 4; i++)   
            if(ExceptionInfo->ContextRecord->Eip == MakePtr(u32, debugHooks.targetFuncs[i], 0))   
                break;   
   
        //  Make sure this single step exception was actually one of ours   
        if(i >= 4)   
            return EXCEPTION_CONTINUE_SEARCH;   
            
        //_cprintf("EXCEPTION_SINGLE_STEP %d ,0x%08X DR7, 0x%08X\n",i,debugHooks.targetFuncs[i],ExceptionInfo->ContextRecord->Dr7 );   
        //  Set the instruction pointer to the address of our hook   
        ExceptionInfo->ContextRecord->Eip = MakePtr(u32, debugHooks.hookFuncs[i], 0);   
        return EXCEPTION_CONTINUE_EXECUTION;   
    }   
   
    return EXCEPTION_CONTINUE_SEARCH;   
}   
   
LONG CALLBACK CHook::Int3HookHandler(PEXCEPTION_POINTERS ExceptionInfo)   
{   
   
    if(ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_BREAKPOINT)   
    {      
           
        if(!int3hooks[MakePtr(FARPROC, ExceptionInfo->ContextRecord->Eip, 0)])   
            return EXCEPTION_CONTINUE_SEARCH;   
   
      //  _cprintf("EXCEPTION_BREAKPOINT\n");    
        //  Set the instruction pointer to the address of our hook   
        ExceptionInfo->ContextRecord->Eip = MakePtr(u32, int3hooks[MakePtr(FARPROC, ExceptionInfo->ContextRecord->Eip, 0)], 0);   
        return EXCEPTION_CONTINUE_EXECUTION;   
    }   
   
    return EXCEPTION_CONTINUE_SEARCH;   
}   
   
//  Called every time a new thread is created, from within the   
//  new thread.  Also, it's called before any of the thread's   
//  code executes.   
u32 CHook::ThreadCallback()   
{   
     _cprintf("ThreadCallback\n");   
        
    if(debugHooks.targetFuncs[0])   
        SetDebugBreak(debugHooks.targetFuncs[0]);   
    if(debugHooks.targetFuncs[1])   
        SetDebugBreak(debugHooks.targetFuncs[1]);   
    if(debugHooks.targetFuncs[2])   
        SetDebugBreak(debugHooks.targetFuncs[2]);   
    if(debugHooks.targetFuncs[3])   
        SetDebugBreak(debugHooks.targetFuncs[3]);   
   
    return threadHook->OriginalFunc(0);   
}   
   
//  Matt Pietrek's function   
IMAGE_SECTION_HEADER *CHook::GetEnclosingSectionHeader(u32 rva)    
{   
    IMAGE_SECTION_HEADER *section = IMAGE_FIRST_SECTION(ntHd);    
    for (u32 i = 0; i < ntHd->FileHeader.NumberOfSections; i++, section++ )   
    {   
        // This 3 line idiocy is because Watcom's linker actually sets the   
        // Misc.VirtualSize field to 0.  (!!! - Retards....!!!)   
        u32 size = section->Misc.VirtualSize;   
        if ( 0 == size )   
            size = section->SizeOfRawData;   
   
        // Is the RVA within this section?   
        if ( (rva >= section->VirtualAddress) &&    
            (rva < (section->VirtualAddress + size)))   
            return section;   
    }   
   
    return NULL;   
}   
   
unsigned long CHook::GetMappedSectionOffset(IMAGE_SECTION_HEADER *seHd)   
{   
    IMAGE_SECTION_HEADER *section = IMAGE_FIRST_SECTION(ntHd);   
    u32 offset = MakeDelta(u32, section, dosHd);   
    for(u32 i = 0; i < ntHd->FileHeader.NumberOfSections; i++, section++)   
    {   
        if(section->Name == seHd->Name)   
        {   
            offset = MakeDelta(u32, section->VirtualAddress, section->PointerToRawData);   
            break;   
        }   
    }   
   
    return offset;   
}   
   
//  This function is also Pietrek's, with a modification by me so that it can handle   
//  images that are mapped into memory.   
void *CHook::GetPtrFromRVA(u32 rva, bool mapped)   
{   
    IMAGE_SECTION_HEADER *pSectionHdr = GetEnclosingSectionHeader(rva);   
    s32 offset = 0;   
   
    if(mapped)   
        offset = GetMappedSectionOffset(pSectionHdr);   
    if (!pSectionHdr)   
        return 0;   
   
    s32 delta = (s32)(pSectionHdr->VirtualAddress-pSectionHdr->PointerToRawData);   
    return (void *) ( (u8 *)dosHd + rva - delta + offset);   
}
