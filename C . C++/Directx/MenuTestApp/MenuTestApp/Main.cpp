/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Main.h"
#include "Drawing.h"

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

// global declarations
cMain Main;

// function prototypes
void initD3D(HWND hWnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);    // closes Direct3D and releases memory

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "WindowClass";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(NULL,
		"WindowClass",
		"DirectX Menu Test | UnknownCheats",
		WS_OVERLAPPEDWINDOW,
		300, 300,
		800, 600,
		NULL,
		NULL,
		hInstance,
		NULL);

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


// this function initializes and prepares Direct3D for use
void initD3D(HWND hWnd)
{
	Main.d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D


	// create a device class using this information and the info from the d3dpp stuct
	Main.d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&Main.d3ddev);
}

bool doonce = false;
// this is the function used to render a single frame
void render_frame(void)
{
	// clear the window to a deep blue
	Main.d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	Main.d3ddev->BeginScene();    // begins the 3D scene

	if(doonce == false)
	{
		D3DXCreateFont(Main.d3ddev, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Verdana", &Main.pFont);
		D3DXCreateLine(Main.d3ddev, &Main.pLiner);
		doonce = true;
	}
	Main.d3ddev->GetViewport(&Main.pViewPort);

	Drawing.StartSceneDrawing();

	Main.d3ddev->EndScene();    // ends the 3D scene

	Main.d3ddev->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen
}


// this is the function that cleans up Direct3D and COM
void cleanD3D(void)
{
	Main.d3ddev->Release();    // close and release the 3D device
	Main.d3d->Release();    // close and release Direct3D
}