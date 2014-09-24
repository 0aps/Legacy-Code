#include <windows.h>
#include <stdio.h>
const HBRUSH VERDE=CreateSolidBrush(RGB(0,255,0));
const HBRUSH NEGRO=CreateSolidBrush(RGB(0,0,0));
const HBRUSH BLANCO=CreateSolidBrush(RGB(255,255,255));
const HBRUSH LILA=CreateSolidBrush(RGB(127,0,255));

EC Enueve D8

int lvl[][2]={
{0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},
{0,1},{0,2},{0,3},{0,4},{0,5},

{0,19},{1,19},{2,19},{3,19},{4,19},{5,19},{6,19},{7,19},{8,19},{9,19},
{0,18},{0,17},{0,16},{0,15},{0,14},

{29,0},{28,0},{27,0},{26,0},{25,0},{24,0},{23,0},{22,0},{21,0},{20,0},
{29,1},{29,2},{29,3},{29,4},{29,5},

{29,19},{28,19},{27,19},{26,19},{25,19},{24,19},{23,19},{22,19},{21,19},{20,19},
{29,18},{29,17},{29,16},{29,15},{29,14},
{-1,-1}
};

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "Viborita GDI";
HINSTANCE miinstance;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    miinstance=hThisInstance;


    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) NEGRO;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Viborita GDI",       /* Title Text */
           (WS_OVERLAPPEDWINDOW) & ~(WS_MAXIMIZEBOX | WS_THICKFRAME), /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           606,                 /* The programs width */
           426,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}



struct Seg
{
    int x, y;
    Seg *next;
};
struct Food
{
    int x,y;
};


class Vibora
{
    Seg *init_seg, *act_seg;
    Food food;
    int mov;
    int x, y;
    public:
    int length;
    Vibora(int nx, int ny, int cant)
    {
        length=cant-1;
        mov=1;
        init_seg=act_seg=new Seg;
        int c=cant;
        while(c!=0)
        {
            act_seg->x=nx-(cant-c);
            act_seg->y=ny;
            act_seg->next=new Seg;
            act_seg=act_seg->next;
            c--;
        }
        act_seg->next=0;
        x=nx;
        y=ny;
        food.x=food.y=-1;
    }

    void putfood()
    {
        Seg *aux_seg;
        nop:
        food.x=((rand()%28)+1);
        food.y=((rand()%18)+1);

        aux_seg=init_seg;
        while(aux_seg->next!=0)
        {
            if(aux_seg->x==food.x && aux_seg->y==food.y) goto nop;
            aux_seg=aux_seg->next;
        }

        for(int i=0;lvl[i][0]>=0;i++)
        {
            if(lvl[i][0]==food.x && lvl[i][1]==food.y) goto nop;
        }
        length++;
        //printf("%i    %i\n", food.x, food.y);

    }

    void dibujar(HDC hdc)
    {
        SelectObject(hdc, BLANCO);
        for(int i=0;lvl[i][0]>=0;i++)
        {
            Rectangle(hdc, lvl[i][0]*20, lvl[i][1]*20, lvl[i][0]*20+20, lvl[i][1]*20+20);
        }
        SelectObject(hdc, VERDE);
        Seg *aux_seg;
        aux_seg=init_seg;
        do
        {
            Rectangle(hdc, aux_seg->x*20+1, aux_seg->y*20+1, aux_seg->x*20+19, aux_seg->y*20+19);
            //printf("%i   %i\n", aux_seg->x, aux_seg->y);
            aux_seg=aux_seg->next;
        }while(aux_seg->next!=0);

        SelectObject(hdc, LILA);
        Rectangle(hdc, food.x*20+1, food.y*20+1, food.x*20+19, food.y*20+19);
    }

    bool boom(int nx, int ny)
    {
        for(int i=0;lvl[i][0]>=0;i++)
        {
            if(lvl[i][0]==nx && lvl[i][1]==ny) return true;
        }
        Seg *aux_seg=init_seg;
        while(aux_seg->next!=0)
        {
            if(aux_seg->x==nx && aux_seg->y==ny) return true;
            aux_seg=aux_seg->next;
        }
        return false;
    }

    bool move()
    {
        Seg *aux_seg;
        bool ret=false;
        switch(mov)
        {
            case 1:
                if(food.x==x+1 && food.y==y) putfood();
                else
                {
                    aux_seg=init_seg;
                    init_seg=init_seg->next;
                    delete aux_seg;
                }
                act_seg->x=++x;
                if(x>29)act_seg->x=x=0;
                act_seg->y=y;
                ret=boom(x,y);
                act_seg->next=new Seg;
                act_seg=act_seg->next;
                act_seg->next=0;
                break;
            case 2:
                if(food.x==x && food.y==y+1) putfood();
                else
                {
                    aux_seg=init_seg;
                    init_seg=init_seg->next;
                    delete aux_seg;
                }
                act_seg->x=x;
                act_seg->y=++y;
                if(y>19)act_seg->y=y=0;
                ret=boom(x,y);
                act_seg->next=new Seg;
                act_seg=act_seg->next;
                act_seg->next=0;
                break;
            case 3:
                if(food.x==x-1 && food.y==y) putfood();
                else
                {
                    aux_seg=init_seg;
                    init_seg=init_seg->next;
                    delete aux_seg;
                }
                act_seg->x=--x;
                if(x<0)act_seg->x=x=29;
                act_seg->y=y;
                ret=boom(x,y);
                act_seg->next=new Seg;
                act_seg=act_seg->next;
                act_seg->next=0;
                break;
            case 4:
                if(food.x==x && food.y==y-1) putfood();
                else
                {
                    aux_seg=init_seg;
                    init_seg=init_seg->next;
                    delete aux_seg;
                }
                act_seg->x=x;
                act_seg->y=--y;
                if(y<0)act_seg->y=y=19;
                ret=boom(x,y);
                act_seg->next=new Seg;
                act_seg=act_seg->next;
                act_seg->next=0;
                break;
        }
        //printf("%i    %i\n", x, y);
        return ret;
    }

    void cmove(int dir)
    {
        if((dir>0 && dir<5) &&
        !(mov==1 && (dir==1 || dir==3)) &&
        !(mov==2 && (dir==2 || dir==4)) &&
        !(mov==3 && (dir==3 || dir==1)) &&
        !(mov==4 && (dir==4 || dir==2)))
        mov=dir;
    }

    ~Vibora()
    {
        Seg *aux_seg;
        aux_seg=init_seg;
        while(aux_seg->next!=0)
        {
            aux_seg=aux_seg->next;
            delete init_seg;
            init_seg=aux_seg;
        }
        delete init_seg;
    }

}vibora(3,3,3);


void refrescar(HWND hwnd)
{
    HDC hdc = GetDC(hwnd);
    UpdateWindow(hwnd);
    SelectObject(hdc, NEGRO);
    Rectangle(hdc, 0, 0, 600, 400);
    vibora.dibujar(hdc);
    ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            static bool moved=false;
            static bool pause=false;
            SetTimer( hwnd , 101 , 64, NULL);
            srand(GetTickCount());
            vibora.putfood();
            break;
        case WM_TIMER:
            if(wParam==101 && !pause)
            {
                moved=false;
                if(vibora.move())
                {
                    pause=true;
                    refrescar(hwnd);
                    char str[256];
                    sprintf(str, "Largo: %i", vibora.length);
                    MessageBox(0, "GAME OVER !", str, MB_OK);
                    PostQuitMessage(0);

                }
                refrescar(hwnd);
                //SendMessage(hwnd, WM_SIZE, 0, 600|(400<<16)); // No Funciona =(
            }
            break;
        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hdc;
            hdc = BeginPaint(hwnd, &ps);
            vibora.dibujar(hdc);
            EndPaint(hwnd, &ps);
            break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
                    pause=true;
                    if(MessageBox(0, "Desea salir del juego?", "Salir?", MB_YESNO)==6)PostQuitMessage(0);
                    pause=false;
                    break;
                case VK_RIGHT:
                    if(!moved)vibora.cmove(1);
                    moved=true;
                    break;
                case VK_DOWN:
                    if(!moved)vibora.cmove(2);
                    moved=true;
                    break;
                case VK_LEFT:
                    if(!moved)vibora.cmove(3);
                    moved=true;
                    break;
                case VK_UP:
                    if(!moved)vibora.cmove(4);
                    moved=true;
                    break;
            }
            break;
        case WM_DESTROY:
            KillTimer(hwnd, 101);
            delete &vibora;
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}
