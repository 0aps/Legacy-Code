    #include <stdio.h>
    #include <stdlib.h>
    #include <winbgim.h>
    #include <math.h>
     
    #define WIDTH 960
    #define HEIGHT 600
    //#define PI 3.1415
     
    int main()
    {
        long long x, y, z;
        initwindow(WIDTH, HEIGHT);
     
        setcolor(COLOR(157, 157, 157));
             
             //desde x,y hasta x2,y2
        line(WIDTH/2, 0, WIDTH/2, HEIGHT);
        line(0, HEIGHT/2, WIDTH, HEIGHT/2);
     
        for (int i=0,p=1; i<=WIDTH; i++)
        {
            x = (i - WIDTH/2);
            if (x!=0) y=x-2;
            if (y<=0)
            {
                z=HEIGHT/2 + abs(y);  //absolute value
            } if (y>0)
            {
                z = abs(HEIGHT/2 - y);
            }
             if (i == 300*p-300){ getchar(); p++; }
            if (z<=HEIGHT && z>=0) putpixel(i, z, COLOR(255, 255, 255));
            printf("f(%d) = %d\n", i, z); //el printf es para ver que pasa con esos valores o.0
     
        }
     
     
        getch();
        closegraph();
        return 0;
    }
