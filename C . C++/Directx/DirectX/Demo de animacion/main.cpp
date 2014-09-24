//**************************************************************************************************
//
// main.cpp : Defines the entry point for the application.
//
// Sprites - this application creates a sprite and a texture and uses the sprite interfaces 
// to display the texture
//
// Created by: Keith Ditchburn 16/01/2003, Modified 24/05/2005
//**************************************************************************************************

#include "main.h"
#include "resource.h"

// Function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Render();
bool InitialiseDirectX(HWND hWnd);
void CleanupDirectX();
bool CreateSprite();
void CreateInstances(HWND hWnd);
void UpdateWorld(HWND hWnd);

// DX global interfaces
LPDIRECT3D9 gD3dObject=NULL;				// the directX object
LPDIRECT3DDEVICE9 gD3dDevice=NULL;			// the directX device
LPD3DXSPRITE gSprite=NULL;					// the D3DX sprite interfaces
LPDIRECT3DTEXTURE9 gTexture=NULL;			// the main animation texture
LPDIRECT3DTEXTURE9 gTextureBackdrop=NULL;	// the backdrop texture

// A structure to hold information for each caveman instance
// Pos - the screen position of the sprite. Z is always 0 but could be used to put sprites behind each other
// frameNumber - current frame number for this sprite
// right - if true the sprite moves to the right else to the left
// topPixel - the offset to the caveman within the texture
// lastUpdate - the time the caveman was last updated
struct TFrame
{
	D3DXVECTOR3 pos;
	int frameNumber;
	bool right;
	int topPixel;
	DWORD lastUpdate;
};

// The cavemen array
TFrame *gCavemen=NULL;

// The number of cavemen to draw down the screen
const int kNumCavemen=8;

// How far to move them each update
const float kMoveAmount=7.0f;

// Time in milliseconds between frames and movement of cavemen
const int kTimeBetweenUpdated=180;

/**************************************************************************************************
Desc: This is the main entry point of the program. 
**************************************************************************************************/
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{ 
	// Describe and register our window class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= 0;	
	wcex.lpfnWndProc	= (WNDPROC)WndProc;																
	wcex.cbClsExtra		= 0;												
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_CGPICON);	
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);					
	wcex.hbrBackground	= 0;						
	wcex.lpszMenuName	= (LPCSTR)IDC_OURMENU;							
	wcex.lpszClassName	= "SomeWindowClass";							
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_CGPICON_SMALL);

	if (RegisterClassEx(&wcex)==0)
		return 0;

	// Create the window
	HWND hWnd=CreateWindow("SomeWindowClass", "Sprite Animation Demo", WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT,CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

	if (hWnd==NULL)
		return 0;

	// Before displaying our window create the D3D device
	if (!InitialiseDirectX(hWnd))
		return 0;

	// Now create the sprite interface and load the textures
	if (!CreateSprite())
	{
		CleanupDirectX();
		return 0;
	}

	// Create the cavemen array
	gCavemen=new TFrame[kNumCavemen];
	assert(gCavemen);

	// Initialise the cavemen instances
	CreateInstances(hWnd);

	// Display the window and force an initial paint
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Enter our program loop - this loop continues until the program exits
	// For maximum performance whenever the application is idle (not getting messages) update and render our scene
    MSG msg;
    ZeroMemory( &msg, sizeof(msg) );
    while( msg.message!=WM_QUIT )
    {
        if( PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else 
		{
			UpdateWorld(hWnd);
            Render();
		}
    }
   
	// The program is now finished so exit gracefully
	if (gCavemen)
		delete[] gCavemen;

	// Clean up DirectX
	CleanupDirectX();

	return msg.wParam;
}

/**************************************************************************************************
Desc: When we created our window class we told windows to call this function whenever a message is 
recieved directed at this window. We did this by providing a pointer to this function.
We can either trap the messages ourselves or let Windows handle the message in a default way by passing 
it to DefWindowProc
**************************************************************************************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	switch (message) 
	{
		case WM_COMMAND:
		{
			int wmId    = LOWORD(wParam); 
			int wmEvent = HIWORD(wParam); 

			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				break;
			}
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
   }
   return DefWindowProc(hWnd, message, wParam, lParam);
}

/**************************************************************************************************
Desc: We use Direct3D to display our scene
**************************************************************************************************/
void Render()
{
	// Clear the back buffer
	HRESULT hr=gD3dDevice->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,0);
	if (FAILED(hr))
		return;

	// Begin the scene
	hr=gD3dDevice->BeginScene();
	if (SUCCEEDED(hr))
	{
		// Draw with alpha blending - needed for our transparent sprites
		gSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Draw the backdrop scaled so it covers more of the screen
		// There are two ways to use sprites, like this where we can build a matrix with
		// rotation, scaling and transform and then set it or where we just use the Draw parameters
		D3DXVECTOR2 pos=D3DXVECTOR2(120,20);

		// Scale the texture 4 times in each dimension
		D3DXVECTOR2 scaling(4.0f,4.0f);

		// out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
		D3DXMATRIX mat;
		D3DXMatrixTransformation2D(&mat,NULL,0.0,&scaling,NULL,0,&pos);

		// Tell the sprite about the matrix
		gSprite->SetTransform(&mat);
		gSprite->Draw(gTextureBackdrop,NULL,NULL,NULL,0xFFFFFFFF);	

		// Set transform back to identity for cavemen
		D3DXMatrixIdentity(&mat);
		gSprite->SetTransform(&mat);

		// Now draw all the cavemen, fill a rect to select the area of the texture to draw
		for (int i=0;i<kNumCavemen;i++)
		{			
			RECT drawRect;

			drawRect.left=gCavemen[i].frameNumber*64;
			drawRect.right=drawRect.left+64;

			drawRect.top=gCavemen[i].topPixel;

			if (gCavemen[i].right)
				drawRect.top+=64;
			else
				drawRect.top+=0;

			drawRect.bottom=drawRect.top+64;

			// This is the other method of using the sprite interface. We do not set a matrix
			// transformation but just use the parameters to pass in the position. This is fine
			// when we do not need to rotate or scale the graphic
			gSprite->Draw(gTexture,&drawRect,NULL,&gCavemen[i].pos,0xFFFFFFFF);
		}

		// Finished drawing. By reusing the same sprite object D3D can maximise batching of the draws
		gSprite->End();

		// Finished rendering
		gD3dDevice->EndScene();
		gD3dDevice->Present(NULL,NULL,NULL,NULL);
	}	
}

/**************************************************************************************************
Desc: To initialise DirectX we must create the Direct3D object and then a device
**************************************************************************************************/
bool InitialiseDirectX(HWND hWnd)
{	
	// Create the D3D object
	gD3dObject=Direct3DCreate9(D3D_SDK_VERSION);
	if (gD3dObject==NULL)
		return FALSE;

	// Fill out some presentation parameters for running in a window
	D3DPRESENT_PARAMETERS presParams;
	ZeroMemory(&presParams,sizeof(presParams));

	presParams.Windowed=TRUE;
	presParams.SwapEffect=D3DSWAPEFFECT_DISCARD;
	presParams.BackBufferFormat=D3DFMT_UNKNOWN;
	presParams.BackBufferCount=1;

	// Create the D3D device
	HRESULT hr=gD3dObject->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING, &presParams, &gD3dDevice);
	if (FAILED(hr))
	{
		// Some cards may not do hardware vertex processing so fall back to software:
		hr=gD3dObject->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, &presParams, &gD3dDevice);
		if (FAILED(hr))
			return FALSE;
	}

	return TRUE;
}

/**************************************************************************************************
Desc: Our application is finishing so we must clean up by deallocating any DirectX objects
Evey DirectX object has a release function to call
**************************************************************************************************/
void CleanupDirectX()
{
	if (gTexture)
		gTexture->Release();

	if (gTextureBackdrop)
		gTextureBackdrop->Release();

	if (gSprite)
		gSprite->Release();

	if (gD3dObject)
		gD3dObject->Release();

	if (gD3dDevice)
		gD3dDevice->Release();
}

/**************************************************************************************************
Desc: Create our sprite object. Return FALSE if an error occured.
Note: We only use one sprite object as this is the most efficient way of doing it. The sprite object
is purely a mechanism for drawing 2D graphics. By using just one and doing all our drawing between
begin and end Direct3D can batch the rendering of the textures most efficiently
**************************************************************************************************/
bool CreateSprite()
{
	HRESULT hr=D3DXCreateSprite(gD3dDevice,&gSprite);
	if (FAILED(hr))
		return FALSE;

	// Load a cavemen texture
	D3DXCreateTextureFromFile(gD3dDevice,"rejilla.jpg",&gTexture);

	// Load a backdrop texture
	D3DXCreateTextureFromFile(gD3dDevice,"rejilla.jpg",&gTextureBackdrop);

	return TRUE;
}

// Create our cavemen instances. 
// Position themn vertically down the screen
// In addition each has a time so we can animate them correctly
void CreateInstances(HWND hWnd)
{
	RECT screenRect;
	GetClientRect(hWnd,&screenRect);
	int topPixel=0;

	for (int i=0;i<kNumCavemen;i++)
	{
		float xPos=(float)(rand()%screenRect.right);

		gCavemen[i].frameNumber=rand()%4;
		gCavemen[i].pos=D3DXVECTOR3(xPos,i*64.0f,0.0f);
		gCavemen[i].right=TRUE;
		gCavemen[i].topPixel=topPixel;
		gCavemen[i].lastUpdate=timeGetTime();

		// Note: these are hard coded
		if (topPixel==0)
			topPixel=129;
		else
			topPixel=0;
	}
}

// Update our world representation
// This fn is called as fast as possible from the message loop. In order to make this demo run
// the same speed on all spec. machines the cavemen are updated at a regular 'tick' in this case 
// 1000/200 = 5 times a second.
// It is generally a good idea in games to update the simulation at a regular rate in order to save 
// processing time as well as provide a consistant speed. You can still render as fast as you want.
void UpdateWorld(HWND hWnd)
{
	DWORD timeNow=timeGetTime();

	RECT screenRect;
	GetClientRect(hWnd,&screenRect);

	for (int i=0;i<kNumCavemen;i++)
	{
		if (timeNow-gCavemen[i].lastUpdate>kTimeBetweenUpdated)
		{
			// Increase frame count and move
			gCavemen[i].frameNumber++;

			if (gCavemen[i].right)
				gCavemen[i].pos.x+=kMoveAmount;
			else
				gCavemen[i].pos.x-=kMoveAmount;

			// Loop to first frame
			if (gCavemen[i].frameNumber>3)
				gCavemen[i].frameNumber=0;

			// Check for edge of screen - if reached switch direction
			if (gCavemen[i].pos.x<0)
			{
				gCavemen[i].pos.x=0;
				gCavemen[i].right=!gCavemen[i].right;
			}
			else if (gCavemen[i].pos.x>screenRect.right-64.0f)
			{
				gCavemen[i].pos.x=screenRect.right-64.0f;
				gCavemen[i].right=!gCavemen[i].right;
			}
			// Randomly just switch direction anyway
			else if (rand()%40==0)
			{
				gCavemen[i].right=!gCavemen[i].right;
			}

			// Remember the last update time
			gCavemen[i].lastUpdate=timeNow;
		}
	}
}
