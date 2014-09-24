/*
"C:\Dev-Cpp\bin\gcc" -o h.exe h.o -nostdlib
 -L"C:\Dev-Cpp\Bin" -lmingw32 -lgcc -lmsvcrt

"C:\Dev-Cpp\bin\ld.exe" -o h.exe h.o
 -L"C:\Dev-Cpp\Bin" -L"C:\Dev-Cpp\lib" -L"C:\Dev-Cpp\lib\gcc\mingw32\3.4.2"
 -lmingw32 -lgcc -lmsvcrt

 .a .lib son librerías estáticas compiladas. Al final son sólo código objeto. (.o)
 hay una convención de anteponer el prefijo lib a los nombres de ciertas librerías
 para que luego sean encontradas por el parámetro -l del linker.

"C:\Program Files\CodeBlocks\MinGW\bin\ld.exe" meh.o -o meh.exe -L"C:\Program
Files\CodeBlocks\MinGW\lib\gcc\mingw32\4.7.1\" -lgcc
En esa ruta está libgcc.a sino no aceptaría el parámetro -gcc

Compilado manual:

"C:\Program Files\CodeBlocks\MinGW\bin\gcc.exe" -S meh.c
"C:\Program Files\CodeBlocks\MinGW\bin\as.exe" meh.s -o meh.o
"C:\Program Files\CodeBlocks\MinGW\bin\ld.exe" meh.o "c:/program files/codeblo
cks/mingw/bin/../lib/gcc/mingw32/4.7.1/../../../crt2.o" -o meh.exe -lmingw32 -lm
svcrt -lkernel32

Con GCC:
C:\Documents and Settings\Owner\Desktop\Programming\C . C++\C++ (variado)\Prueba
s>"C:\Program Files\CodeBlocks\MinGW\bin\gcc.exe" meh.c -o h.exe -nostdlib "c:/p
rogram files/codeblocks/mingw/bin/../lib/gcc/mingw32/4.7.1/../../../crt2.o" -lmi
ngw32 -lmsvcrt -lkernel32

*/

#define PI 3.14
int suma(int pedro)
{
    return pedro*pedro;
}

int __main (void)
{
        printf("hi, %d\r\n", suma(10) );
         //getch();
        //getchar();

        return 0;
}
