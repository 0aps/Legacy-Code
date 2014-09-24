 //  1.
      // include the basic windows header files and the Direct3D header file
   //2.
      #include <windows.h>
   //3.
      #include <windowsx.h>
   //4.
      #include <d3d9.h>
   //5.
       
   //6.
      // define the screen resolution and keyboard macros
   //7.
      #define SCREEN_WIDTH 800
   //8.
      #define SCREEN_HEIGHT 600
   //9.
      #define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
  //10.
      #define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
  //11.
       
  //12.
      // include the Direct3D Library file
  //13.
      #pragma comment (lib, "d3d9.lib")
  //14.
       
  //15.
      // global declarations
  //16.
      LPDIRECT3D9 d3d; // the pointer to our Direct3D interface
  //17.
      LPDIRECT3DDEVICE9 d3ddev; // the pointer to the device class
  //18.
       
  //19.
      // function prototypes
  //20.
      void initD3D(HWND hWnd); // sets up and initializes Direct3D
  //21.
      void render_frame(void); // renders a single frame
  //22.
      void cleanD3D(void); // closes Direct3D and releases memory
  //23.
       
  //24.
      // the WindowProc function prototype
  //25.
      LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
  //26.
       
  //27.
       
  //28.
      // the entry point for any Windows program
  //29.
      int WINAPI WinMain(HINSTANCE hInstance,
  //30.
      HINSTANCE hPrevInstance,
  //31.
      LPSTR lpCmdLine,
  //32.
      int nCmdShow)
  //33.
      {
  //34.
      HWND hWnd;
  //35.
      WNDCLASSEX wc;
  //36.
       
  //37.
      ZeroMemory(&wc, sizeof(WNDCLASSEX));
  //38.
       
  //39.
      wc.cbSize = sizeof(WNDCLASSEX);
  //40.
      wc.style = CS_HREDRAW | CS_VREDRAW;
  //41.
      wc.lpfnWndProc = WindowProc;
  //42.
      wc.hInstance = hInstance;
  //43.
      wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  //44.
      // wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // not needed any more
  //45.
      wc.lpszClassName = "WindowClass";
  //46.
       
  //47.
      RegisterClassEx(&wc);
  //48.
       
  //49.
      hWnd = CreateWindowEx(NULL,
  //50.
      "WindowClass",
  //51.
      "Our Direct3D Program",
  //52.
      WS_EX_TOPMOST | WS_POPUP, // fullscreen values
  //53.
      0, 0, // the starting x and y positions should be 0
  //54.
      SCREEN_WIDTH, SCREEN_HEIGHT, // set the window to 640 x 480
  //55.
      NULL,
  //56.
      NULL,
  //57.
      hInstance,
  //58.
      NULL);
  //59.
       
  //60.
      ShowWindow(hWnd, nCmdShow);
  //61.
       
  //62.
      // set up and initialize Direct3D
  //63.
      initD3D(hWnd);
  //64.
       
  //65.
      // enter the main loop:
  //66.
       
  //67.
      MSG msg;
  //68.
       
  //69.
      while(TRUE)
  //70.
      {
  //71.
      while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
  //72.
      {
  //73.
      TranslateMessage(&msg);
  //74.
      DispatchMessage(&msg);
  //75.
      }
  //76.
       
  //77.
      if(msg.message == WM_QUIT)
  //78.
      break;
  //79.
       
  //80.
      render_frame();
  //81.
       
  //82.
      // check the 'escape' key
  //83.
      if(KEY_DOWN(VK_ESCAPE))
  //84.
      PostMessage(hWnd, WM_DESTROY, 0, 0);
  //85.
      }
  //86.
       
  //87.
      // clean up DirectX and COM
  //88.
      cleanD3D();
  //89.
       
  //90.
      return msg.wParam;
  //91.
      }
  //92.
       
  //93.
       
  //94.
      // this is the main message handler for the program
  //95.
      LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
  //96.
      {
  //97.
      switch(message)
  //98.
      {
  //99.
      case WM_DESTROY:
 //100.
      PostQuitMessage(0);
 //101.
      return 0;
 //102.
      break;
 //103.
      }
 //104.
       
 //105.
      return DefWindowProc (hWnd, message, wParam, lParam);
 //106.
      }
 //107.
       
 //108.
       
 //109.
      // this function initializes and prepares Direct3D for use
 //110.
      void initD3D(HWND hWnd)
 //111.
      {
 //112.
      d3d = Direct3DCreate9(D3D_SDK_VERSION); // create the Direct3D interface
 //113.
       
 //114.
      D3DPRESENT_PARAMETERS d3dpp; // create a struct to hold various device information
 //115.
       
 //116.
      ZeroMemory(&d3dpp, sizeof(d3dpp)); // clear out the struct for use
 //117.
      d3dpp.Windowed = FALSE; // program fullscreen, not windowed
 //118.
      d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // discard old frames
 //119.
      d3dpp.hDeviceWindow = hWnd; // set the window to be used by Direct3D
 //120.
      d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; // set the back buffer format to 32-bit
 //121.
      d3dpp.BackBufferWidth = SCREEN_WIDTH; // set the width of the buffer
 //122.
      d3dpp.BackBufferHeight = SCREEN_HEIGHT; // set the height of the buffer
// 123.
       
 //124.
       
 //125.
      // create a device class using this information and the info from the d3dpp stuct
 //126.
      d3d->CreateDevice(D3DADAPTER_DEFAULT,
 //127.
      D3DDEVTYPE_HAL,
 //128.
      hWnd,
 //129.
      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
 //130.
      &d3dpp,
 //131.
      &d3ddev);
// 132.
      }
 //133.
       
 //134.
       
 //135.
      // this is the function used to render a single frame
 //136.
      void render_frame(void)
 //137.
      {
// 138.
      // clear the window to a deep blue
 //139.
      d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
// 140.
       
 //141.
      d3ddev->BeginScene(); // begins the 3D scene
 //142.
       
// 143.
      // do 3D rendering on the back buffer here
 //144.
       
// 145.
      d3ddev->EndScene(); // ends the 3D scene
 //146.
       
 //147.
      d3ddev->Present(NULL, NULL, NULL, NULL); // displays the created frame on the screen
 //148.
      }
// 149.
       
 //150.
       
 //151.
      // this is the function that cleans up Direct3D and COM
// 152.
      void cleanD3D(void)
// 153.
      {
// 154.
      d3ddev->Release(); // close and release the 3D device
// 155.
      d3d->Release(); // close and release Direct3D

      }
