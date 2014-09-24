/*
// WinDemo.cpp : Defines the entry point for the application.
// 
// Demonstrates some of the GDI functionality for displaying graphics
//
// Keith Ditchburn (2005)
*/

#include "stdafx.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;							// current instance
TCHAR szTitle[MAX_LOADSTRING];				// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];		// The window class text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void				PaintWindow(HDC hdc);

// Current mode enums
enum EMode
{
	eDisplayText,
	eDisplayLines,
	eDisplayFilled,
	eDisplayPixels
};

// Global variable for current mode
EMode gMode=eDisplayText;

// Various defines
#define NUM_POINTS	12
#define NUM_PENS	30
#define NUM_BRUSHES	30
#define NUM_PIXELS	1000

// Global arrays
POINT gPoints[NUM_POINTS];
HPEN gPens[NUM_PENS];
HBRUSH gBrushes[NUM_BRUSHES];

// Global window handle
HWND gHwnd;

// Entry point
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) 
{
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINDEMO, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
		return FALSE;

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_WINDEMO);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

// Register a window class
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_WINDEMO);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName	= (LPCSTR)IDC_WINDEMO;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

// Creates the main window
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// Store instance handle in our global variable
	hInst = hInstance; 

	// Create a window
	gHwnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!gHwnd)
		return FALSE;

	// Cause first show of window
	ShowWindow(gHwnd, nCmdShow);
	UpdateWindow(gHwnd);

	return TRUE;
}

// Callback that processes messages for the main window.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	// Parse the menu selections:
	case WM_COMMAND:		
		switch (LOWORD(wParam))
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_TEXT:
			gMode=eDisplayText;
			InvalidateRect(hWnd,NULL,TRUE);
			break;
		case IDM_LINES:
			gMode=eDisplayLines;
			InvalidateRect(hWnd,NULL,TRUE);
			break;
		case IDM_FILLED:
			gMode=eDisplayFilled;
			InvalidateRect(hWnd,NULL,TRUE);
			break;
		case IDM_PIXELS:
			gMode=eDisplayPixels;
			InvalidateRect(hWnd,NULL,TRUE);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	// Force a redraw when a key is pressed
	case WM_KEYDOWN:
		InvalidateRect(hWnd,NULL,TRUE);
		break;

	// Paint our window
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			PaintWindow(hdc);			
			EndPaint(hWnd, &ps);			
		}
		break;

	// Kill window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

// Display some text
void DisplayText(HDC hdc)
{
	char buf[2048];

	int x=50;
	int y=60;

	int len=sprintf(buf,"Hello World!");
	TextOut(hdc,x,y,buf,len);

	y+=50;
	len=sprintf(buf,"The above test was displayed using the GDI function: TextOut");
	TextOut(hdc,x,y,buf,len);

	y+=20;
	len=sprintf(buf,"The code is TextOut(hdc,50,50,""Hello World"",12)");
	TextOut(hdc,x,y,buf,len);

	SetTextColor(hdc,RGB(rand()%255,rand()%255,rand()%255));

	y+=20;
	len=sprintf(buf,"You can also change the colour of the text");
	TextOut(hdc,x,y,buf,len);

	SetTextColor(hdc,RGB(0,0,255));

	y+=20;
	len=sprintf(buf,"Using the SetTextColour function");
	TextOut(hdc,x,y,buf,len);

	SetTextColor(hdc,RGB(0,0,0));

	y+=20;
	len=sprintf(buf,"To see other GDI functions select from the menu");
	TextOut(hdc,x,y,buf,len);
}

// Draw some lines
void DisplayLines(HDC hdc)
{
	for (int i=0;i<NUM_POINTS-1;i++)
	{
		RECT rct;
		GetClientRect(gHwnd,&rct);

		gPoints[i].x=rand()%rct.right;
		gPoints[i].y=rand()%rct.bottom;
	}

	gPoints[NUM_POINTS-1].x=gPoints[0].x;
	gPoints[NUM_POINTS-1].y=gPoints[0].y;

	int p=rand()%NUM_PENS;

	HGDIOBJ old=SelectObject(hdc,gPens[p]);

	Polyline(hdc,gPoints,NUM_POINTS);

	SelectObject(hdc,old);

	char buf[2048];

	int x=50;
	int y=60;

	int len=sprintf(buf,"Lines have been drawn using Polyline(...)");
	TextOut(hdc,x,y,buf,len);

	y+=20;
	len=sprintf(buf,"The line style is randomised, as is the colour and width");
	TextOut(hdc,x,y,buf,len);
}

// Draw filled rectangles and ellipses
void DisplayFilled(HDC hdc)
{
	RECT rct;
	GetClientRect(gHwnd,&rct);

	RECT r;

	for (int i=0;i<10;i++)
	{
		r.left=rand()%rct.right/2;
		r.right=r.left+rand()%rct.right/2;

		r.top=rand()%rct.bottom/2;
		r.bottom=r.top+rand()%rct.bottom/2;

		FillRect(hdc,&r,gBrushes[rand()%NUM_BRUSHES]);
	}

	for (i=0;i<10;i++)
	{
		r.left=rand()%rct.right/2;
		r.right=r.left+rand()%rct.right/2;

		r.top=rand()%rct.bottom/2;
		r.bottom=r.top+rand()%rct.bottom/2;

		HGDIOBJ old=SelectObject(hdc,gBrushes[rand()%NUM_BRUSHES]);

		Ellipse(hdc,r.left,r.top,r.right,r.bottom);

		SelectObject(hdc,old);
	}

	char buf[2048];

	int x=50;
	int y=60;

	int len=sprintf(buf,"Filled rectangles have been drawn using FillRect(...)");
	TextOut(hdc,x,y,buf,len);

	y+=20;
	len=sprintf(buf,"Filled ellipses have been drawn using Ellipse(...)");
	TextOut(hdc,x,y,buf,len);

	y+=20;
	len=sprintf(buf,"The brush colour is randomised");
	TextOut(hdc,x,y,buf,len);
}

// Set some pixels
void DisplayPoints(HDC hdc)
{
	RECT rct;
	GetClientRect(gHwnd,&rct);

	// Draw random points on screen
	for (int i=0;i<NUM_PIXELS;i++)
	{
		int x=rand()%rct.right;
		int y=rand()%rct.bottom;

		SetPixel(hdc,x,y,RGB(rand()%255,rand()%255,rand()%255));
	}

	int x=50;
	int y=60;

	char buf[2048];
	int len=sprintf(buf,"Pixels have been drawn using SetPixel(...)");
	TextOut(hdc,x,y,buf,len);

	y+=20;
	len=sprintf(buf,"1000 are drawn at random positions with random colours");
	TextOut(hdc,x,y,buf,len);
}

// Create a load of pens
void CreatePens()
{
	for (int i=0;i<NUM_PENS;i++)
	{
		int style=rand()%4;
		int width=1+rand()%8;
		COLORREF col=RGB(rand()%255,rand()%255,rand()%255);

		gPens[i]=CreatePen(style,width,col);
	}

	for (i=0;i<NUM_BRUSHES;i++)
		gBrushes[i]=CreateSolidBrush(RGB(rand()%255,rand()%255,rand()%255));
}

// Paint the window
// Depending on mode calls a different display function
void PaintWindow(HDC hdc)
{
	static bool firstTimeCalled=TRUE;

	if (firstTimeCalled)
	{
		CreatePens();
		firstTimeCalled=FALSE;
	}

	switch(gMode)
	{
	case eDisplayText:
		DisplayText(hdc);
		break;
	case eDisplayLines:
		DisplayLines(hdc);
		break;
	case eDisplayFilled:
		DisplayFilled(hdc);
		break;
	case eDisplayPixels:
		DisplayPoints(hdc);
		break;
	}

	char buf[2048];
	int len=sprintf(buf,"Press any key to redraw");

	TextOut(hdc,50,300,buf,len);
}
