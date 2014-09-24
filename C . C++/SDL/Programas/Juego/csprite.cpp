#include <SDL/SDL.h>
#include <SDL/SDL_IMAGE.h>
#include "csprite.h"

// Sprite Class implementation
void CFrame::load(char *path) 
{
img=IMG_Load(path);

// Asignamos el color transparente al color rojo.

//SDL_SetColorKey(img,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img->format,0,0,0));
SDL_SetColorKey(img,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img->format,255,0,0));

img=SDL_DisplayFormat(img); //mayor rapides en el blitting

}

void CFrame::unload(){
SDL_FreeSurface(img);
}

CSprite::CSprite(int nf) {
sprite=new CFrame[nf];
nframes=nf;
cont=0;
}

CSprite::CSprite() {
int nf=1;
sprite=new CFrame[nf];
nframes=nf;
cont=0;
}

void CSprite::finalize() {
int i;
for (i=0 ; i<=nframes-1 ; i++)
sprite[i].unload();
}

void CSprite::addframe(CFrame frame) {
if (cont<nframes) {
sprite[cont]=frame;
cont++;
}
}

void CSprite::selframe(int nf) {
if (nf<=nframes) {
estado=nf;
}
}

void CSprite::draw(SDL_Surface *superficie) {
SDL_Rect dest;
dest.x=posx;
dest.y=posy;
SDL_BlitSurface(sprite[estado].img,NULL,superficie,&dest);
}

int CSprite::colision(CSprite sp) {
int w1,h1,w2,h2,x1,y1,x2,y2;

w1=getw(); // ancho del sprite1
h1=geth(); // altura del sprite1

w2=sp.getw(); // ancho del sprite2
h2=sp.geth(); // alto del sprite2

x1=getx(); // pos. X del sprite1
y1=gety(); // pos. Y del sprite1

x2=sp.getx(); // pos. X del sprite2
y2=sp.gety(); // pos. Y del sprite2

if ( ( (x1+w1) > x2) && ( (y1+h1) > y2) && ( (x2+w2) > x1) && ( (y2+h2) > y1) ) 
{
return TRUE;
} else {
return FALSE;
       }
       
}
