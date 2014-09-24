{*(float*)(dwPlayerPtr+OFS_NORECOIL1) = 0;
*(float*)(dwPlayerPtr+OFS_NORECOIL2) = 0;
*(float*)(dwPlayerPtr+OFS_NORECOIL3) = 0;}


{*(float*) No_Spread = 0;}

//--------------------------Define Windows--------------------------//
#include <windows.h>
#include <stdio.h>
//--------------------------End Define Windows----------------------//

//--------------------------Define Addies---------------------------//
#define Playerpointer 0x00
#define Serverpointer 0x00
#define OFS_NORECOIL1 0x00
#define OFS_NORECOIL2 0x00
#define OFS_NORECOIL3 0x00
#define No_Spread 0x00
//--------------------------End Define Addies-----------------------//

//--------------------------Define Hackthread-----------------------//
DWORD *ingame= (DWORD*)Playerpointer;
DWORD *outgame= (DWORD*)Serverpointer;
//--------------------------End Define Hackthread-------------------//

//--------------------------Start Functions-------------------------//
void PlayerHacks() 
{
DWORD dwPlayerPtr = *(DWORD*)Playerpointer;
if(dwPlayerPtr != 0){

//No Recoil
{*(float*)(dwPlayerPtr+OFS_NORECOIL1) = 0;
*(float*)(dwPlayerPtr+OFS_NORECOIL2) = 0;
*(float*)(dwPlayerPtr+OFS_NORECOIL3) = 0;}
//End No Recoil

//No Spread
{*(float*) No_Spread = 0;}
//End No Spread

}} //End PlayerHacks

void ServerHacks() // Start ServerHacks
{
DWORD dwSrvrPtr=*(DWORD*)Serverpointer;
if(dwSrvrPtr!=0){

}} //End ServerHacks
//--------------------------End Functions---------------------------//

//-------------------------HackThread-------------------------------//
void HackThread() 
{
for(;; ) 
{
if(*ingame)
{
PlayerHacks();
}
if(*outgame)
{
ServerHacks();
}
}
Sleep(200); 
}
//--------------------------End HackThread-------------------------//

//--------------------------End Hack-------------------------------//
BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved)
{
if(dwReason == DLL_PROCESS_ATTACH)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HackThread, 0, 0, 0);
}
return TRUE;
}
//-----------------
