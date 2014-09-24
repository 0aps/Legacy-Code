#include "Design.h"
#include "Loads.h"
#include "Images.h"
#include <d3d9.h>
#include <windows.h>
#include <windowsx.h>

#pragma comment (lib, "d3d9.lib")

HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{    
    if (runOnce)
    {
        runOnce = false;
        GetCenterScreen(pDevice); // Only needs to be ran once
    }
    if(TexMenu == NULL)D3DXCreateTextureFromFileInMemory(pDevice, &_Menu, sizeof(_Menu), &TexMenu);// If NULL keep trying to create the texture
    if(TexCursor == NULL)D3DXCreateTextureFromFileInMemory(pDevice, &_Cursor, sizeof(_Cursor), &TexCursor);
    if(TexNorm == NULL)D3DXCreateTextureFromFileInMemory(pDevice, &_Norm, sizeof(_Norm), &TexNorm);
    if(TexActive == NULL)D3DXCreateTextureFromFileInMemory(pDevice, &_Active, sizeof(_Active), &TexActive);
    if(SptMenu == NULL)D3DXCreateSprite(pDevice, &SptMenu);
    if(pFont == NULL) D3DXCreateFont(pDevice, 10, 0, FW_THIN, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Lucida Console", &pFont); // I like this font setting, You may adjust to your likings

    SptMenu->Begin(D3DXSPRITE_ALPHABLEND); // READ TUTORIAL TO SEE WHY I DO THIS

    menuTextX = (menuX + 14); // This is for Text Alignment to the menu, needs to be constantly updated just incase you move the menu
    menuTextY = (menuY + 38);

    if (bMenu)
    {
        DrawTexture(menuX, menuY, TexMenu); // If menu is shown draw the menu, duh!
        for (int i = 0; i < 4; i++) // Render the Menu Options
        {
            if (_Features[i]) // You can make a function like DrawMenuOption(bool enaled) or you can do this.
                DrawTexture(menuX + 5, (menuY+33) + (19 * i), TexActive); // You will have to self, align this for yourself
            else
                DrawTexture(menuX + 5, (menuY+33) + (19 * i), TexNorm);

            PrintText(pFont, menuTextX, menuTextY + (19*i), tBlack, Features[i]); // Prints text over the buttons so you know what you are clicking.
        }
    }
    DrawMouse(pDevice); // Draws the mouse *facepalm*
    SptMenu->End(); // End the Sprite
    return oEndScene(pDevice); // Ends our DX EndScene hook
}

DWORD WINAPI MyInput(LPVOID)
{
    while (1)
    {
        if(GetAsyncKeyState(VK_F2)&0x8000)
            bMenu = !bMenu;
        Sleep(200);
    }
    return 0;
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
    if(dwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(0,0,MyThread,0,0,0); // Take Input
        CreateThread(0,0,MyInput,0,0,0); // Actually do the hook
    }

    return TRUE;
}  
