#include <SDL/SDL.h>
#include <windows.h>
#include <stdio.h>

SDL_Surface* screen;

class Timer
{
    Uint32 tiempo;
    Uint16 frame_milisec;
    public:
    Timer(Uint16 n_frame_milisec)
    {
        tiempo=SDL_GetTicks();
        frame_milisec=n_frame_milisec;
    }

    void w8()
    {
        while(SDL_GetTicks()-tiempo<frame_milisec) SDL_Delay(2);
        tiempo=SDL_GetTicks();
    }
};

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
    Uint32 negro, verde, lila, blanco;
    public:
    int length;

    void setcolors()
    {
        negro=SDL_MapRGB(screen->format, 0, 0, 0);
        verde=SDL_MapRGB(screen->format, 0, 255, 0);
        blanco=SDL_MapRGB(screen->format, 255, 255, 255);
        lila=SDL_MapRGB(screen->format, 127, 0, 255);
    }

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
        setcolors();
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

    void dibujar()
    {
        SDL_Rect auxrect;

        SDL_FillRect(screen, 0, negro);

        //SDL_FillRect(screen, &auxrect, auxcolor);

        auxrect.w=auxrect.h=20;
        for(int i=0;lvl[i][0]>=0;i++)
        {
            auxrect.x=lvl[i][0]*20;
            auxrect.y=lvl[i][1]*20;
            SDL_FillRect(screen, &auxrect, blanco);
        }

        auxrect.w=auxrect.h=18;
        Seg *aux_seg;
        aux_seg=init_seg;
        do
        {
            auxrect.x=aux_seg->x*20+1;
            auxrect.y=aux_seg->y*20+1;
            SDL_FillRect(screen, &auxrect, verde);
            aux_seg=aux_seg->next;
        }while(aux_seg->next!=0);

        auxrect.x=food.x*20+1;
        auxrect.y=food.y*20+1;
        SDL_FillRect(screen, &auxrect, lila);
        SDL_Flip(screen);
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

};

int main ( int argc, char** argv )
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )return 1;
    atexit(SDL_Quit);
    if(!(screen = SDL_SetVideoMode(600, 400, 16,SDL_HWSURFACE|SDL_DOUBLEBUF)))return 1;
    SDL_WM_SetCaption("Viborita SDL", NULL);

    //SDL_Rect dstrect;

    Vibora vibora(3,3,3);
    Timer timer(64);
    bool done = false;
    bool moved=false;
    bool pause=false;
    srand(GetTickCount());
    vibora.putfood();
    while (!done)
    {
        moved=false;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                done = true;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        if(MessageBox(0, "Desea salir del juego?", "Salir?", MB_YESNO)==6)done=true;
                        break;
                    case SDLK_RIGHT:
                        if(!moved)vibora.cmove(1);
                        moved=true;
                        break;
                    case SDLK_DOWN:
                        if(!moved)vibora.cmove(2);
                        moved=true;
                        break;
                    case SDLK_LEFT:
                        if(!moved)vibora.cmove(3);
                        moved=true;
                        break;
                    case SDLK_UP:
                        if(!moved)vibora.cmove(4);
                        moved=true;
                        break;
                }
            }
        }

        timer.w8();
        if(!pause)
        {
            if(vibora.move())
            {
                vibora.dibujar();
                char str[256];
                sprintf(str, "Largo: %i", vibora.length);
                MessageBox(0, "GAME OVER !", str, MB_OK);
                done=true;
            }
        }
        vibora.dibujar();
    }
    delete &vibora;
    return 0;
}
