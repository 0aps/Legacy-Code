#define flt (float)
float centerScreenX, centerScreenY;
float menuX, menuY, menuTextX, menuTextY;
tagPOINT Pos;

char* Features[] = { "Hack 1", "Hack 2", "Hack 3", "Hack 4" };
bool _Features[4]; // Create Bools to toggle for the hacks

void DrawTexture(int x, int y, LPDIRECT3DTEXTURE9 dTexture)
{
    SptMenu->Draw(dTexture,NULL,NULL,&D3DXVECTOR3(flt x,flt y, 0.0f), 0xFFFFFFFF);
    return;
}

void PrintText(LPD3DXFONT Font, long x, long y, D3DCOLOR fontColor, char *text, ...)
{ 
    RECT rct;   
    rct.left     = x - 1;   
    rct.right    = x + 1;   
    rct.top      = y - 1 ;   
    rct.bottom   = y + 1; 

    if(!text) { return; }
    va_list va_alist;
    char logbuf[256] = {0};
    va_start (va_alist, text);
    _vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end (va_alist);
    RECT FontRect = { x, y, x, y };
    Font->DrawText(SptMenu, logbuf, -1, &rct, DT_NOCLIP, fontColor); 
}

void GetCenterScreen(LPDIRECT3DDEVICE9 pDevice)
{
    pDevice->GetViewport(&pViewPort);
    centerScreenX = ( float )pViewPort.Width / 2;//Horizontal Position
    centerScreenY = ( float )pViewPort.Height / 2;//Vertical Position
    menuX = (centerScreenX - 110);
    menuY = (centerScreenY - 225);
}

void DrawMouse(LPDIRECT3DDEVICE9 pDevice)
{
    GetCursorPos(&Pos);
    if (bMenu)
    {
        DrawTexture(Pos.x, Pos.y, TexCursor);
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) //0x8000
        {
            if ((Pos.x > menuX) && (Pos.x < menuX+138) && (Pos.y > menuY) && (Pos.y < menuY+20))
            {
                menuX = Pos.x - 68; // Move the Menu/ Adjust this to the center of your moveable part of the menu
                menuY = Pos.y - 10;
            }
            
            for (int i = 0; i < 4; i++) // Change this to the amount of features you have
            {
                if ((Pos.x > menuX + 5) && (Pos.x < menuX+125) && (Pos.y > menuY+33 + (19 * i)) && (Pos.y < (menuY+50 + (19 * i))))
                {
                    _Features[i] = !_Features[i];
                    Sleep(100); // So you don't get Rapid-Fire Toggling
                }
            }
        }
    }
}  
