// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>

// define the screen resolution
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma warning (disable: 68)


// global declarations
LPDIRECT3D9 d3d; // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev; // the pointer to the device class
char *clase = "clase";
LPD3DXFONT g_pFont;
LPDIRECT3DTEXTURE9 d3dtex;
LPD3DXSPRITE d3dsprite;
LPD3DXFONT m_font;


// function prototypes
void initD3D(HWND hWnd); // sets up and initializes Direct3D
void render_frame(void); // renders a single frame
void cleanD3D(void); // closes Direct3D and releases memory

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    FreeConsole();
    HWND hWnd;
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW+1;    // not needed any more
    wc.lpszClassName = clase;

    RegisterClassEx(&wc);

    hWnd = CreateWindowEx(NULL,
                          clase,
                          "Our Direct3D Program",
                          WS_EX_TOPMOST | WS_POPUP,    // fullscreen values
                          0, 0,    // the starting x and y positions should be 0
                          SCREEN_WIDTH, SCREEN_HEIGHT,    // set the window to 640 x 480
                          NULL,
                          NULL,
                          hInstance,
                          0);

    ShowWindow(hWnd, nCmdShow);

    // set up and initialize Direct3D
    initD3D(hWnd);

    // enter the main loop:

    MSG msg;

    while(TRUE)
    {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if(msg.message == WM_QUIT)
            break;

        render_frame();
    }

    // clean up DirectX and COM
    cleanD3D();

    return msg.wParam;
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            } break;
    }

    return DefWindowProc (hWnd, message, wParam, lParam);
}


// ###########################################################################################
// ###########################################################################################


// this function initializes and prepares Direct3D for use
void initD3D(HWND hWnd)
{
    d3d = Direct3DCreate9(D3D_SDK_VERSION); // create the Direct3D interface

    D3DPRESENT_PARAMETERS d3dpp; // create a struct to hold various device information

    ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
    d3dpp.Windowed = TRUE;    // program fullscreen, not windowed
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
    d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
//    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;    // set the back buffer format to 32-bit
//    d3dpp.BackBufferWidth = SCREEN_WIDTH;    // set the width of the buffer
//    d3dpp.BackBufferHeight = SCREEN_HEIGHT;    // set the height of the buffer


    // create a device class using this information and the info from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT,
                      D3DDEVTYPE_HAL,
                      hWnd,
                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                      &d3dpp,
                      &d3ddev);
                      
    D3DXCreateSprite(d3ddev,&d3dsprite);
    
    D3DXCreateFont( d3ddev, 20, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, 
                OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
                TEXT("Arial"), &m_font );
                      
}


// this is the function used to render a single frame
void render_frame(void)
{
    // clear the window to a deep blue
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
    d3ddev->BeginScene();    // begins the 3D scene
    
/*    
// =========================== Sprite ==========================

d3dsprite->Begin(D3DXSPRITE_ALPHABLEND);

// Texture being used is 64 by 64:
D3DXVECTOR2 spriteCentre=D3DXVECTOR2(32.0f,32.0f);

// Screen position of the sprite
D3DXVECTOR2 trans=D3DXVECTOR2(50.0f,80.0f);

// Rotate based on the time passed
float rotation=timeGetTime()/500.0f;

// Build our matrix to rotate, scale and position our sprite
D3DXMATRIX mat;

D3DXVECTOR2 scaling(2.0f,2.0f);

// out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
D3DXMatrixTransformation2D(&mat,NULL,0.0,&scaling,&spriteCentre,rotation,&trans);

// Tell the sprite about the matrix
d3dsprite->SetTransform(&mat);

// Draw the sprite
d3dsprite->Draw(d3dtex,NULL,NULL,NULL,0xFFFFFFFF);

// Thats it
d3dsprite->End();
*/
// =============================== Font text ==========================

void DisplaySomeText();

                


// ============================CrosFire ======================
        int x = ( GetSystemMetrics( 0 ) / 2); 
        int y = ( GetSystemMetrics( 1 ) / 2); 
        D3DRECT rec = { x - 10, y, x + 10, y + 1}; 
        D3DRECT rec2 = { x, y - 10, x + 1, y + 10}; 
        d3ddev->Clear(1, &rec, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 255, 0, 0), 0, 0);
        d3ddev->Clear(1, &rec2, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 255, 0, 0), 0, 0);

// =========================== Dibujar texto ====================
  if( !g_pFont )
  D3DXCreateFont( d3ddev, 15, 0, FW_MEDIUM, 1, 0 ,DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SCRIPT, "Consolas", &g_pFont );
  RECT    rtFontPos = { 300, 400, 10, 10 };
  g_pFont->DrawText( NULL, "Dos de un Lindo Palo", -1, &rtFontPos, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB( 255, 0, 0 ) );

// =========================================================================
    
    
    // do 3D rendering on the back buffer here
    d3ddev->EndScene();    // ends the 3D scene
    d3ddev->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen

}


// this is the function that cleans up Direct3D and COM
void cleanD3D(void)
{
    d3ddev->Release(); // close and release the 3D device
    d3d->Release(); // close and release Direct3D
}


void DisplaySomeText()
{

      // Create a colour for the text - in this case blue
      D3DCOLOR fontColor = D3DCOLOR_ARGB(0, 40, 100,0);   

      // Create a rectangle to indicate where on the screen it should be drawn
      RECT rct;
      rct.left=2;
      rct.right=780;
      rct.top=10;
      rct.bottom=rct.top+20;
       
      // Draw some text
      m_font->DrawText(NULL, "Hello World", -1, &rct, 0, fontColor );
      m_font->Release();
}




