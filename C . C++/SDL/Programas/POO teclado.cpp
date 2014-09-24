#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

//******************
//
// CLASES
//
//******************
// la clase frame contiene la superficie con la imagen

class Frame {
public:
SDL_Surface *img;
void cargar(char archivo[50]);
};

class Elemento {
private:
int x, y; // posicion actual del elemento en la pantalla
Frame sprite; // imagen del elemento

public:
Elemento();

// las siguientes funciones actualizan y recogen los
// valores de posición de la pantalla
void setX(int valor_x) { x = valor_x; }
void setY(int valor_y) { y = valor_y; }
void addX(int valor_x) { x += valor_x; }
void addY(int valor_y) { y += valor_y; }
int getX() { return x; }
int getY() { return y; }

// esta función añade la imagen al elemento
void addFrame(char archivo[50]);

// esta función dibuja la imagen en la pantalla
void dibujar(SDL_Surface *screen);
};

//******************
//
// CLASE FRAME
//
//******************

void Frame::cargar(char archivo[50]) {
img = IMG_Load (archivo);
}

//******************
//
// CLASE ELEMENTO
//
//******************

Elemento::Elemento() {
x = 0;
y = 0;
}

void Elemento::addFrame(char archivo[50]) {
sprite.cargar(archivo);
}

void Elemento::dibujar(SDL_Surface *screen) {
SDL_Rect rect;
rect.x = x;
rect.y = y;
SDL_BlitSurface(sprite.img, NULL, screen, &rect );
}


//******************
//
// EMPEZAMOS
//
//******************
// esta función crea un fondo de color negro
SDL_Surface* crearFondo() {

/* Creamos las variables necesarias */
SDL_Surface *surface;
Uint32 rmask, gmask, bmask, amask;

/* damos valores a las variables */
rmask = 0xff000000;
gmask = 0x00ff0000;
bmask = 0x0000ff00;
amask = 0x00000000;

surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 640, 480, 16, rmask, gmask, bmask, amask);

if(surface == NULL) {
fprintf(stderr, "CreateRGBSurface ha fallado: %s\n", SDL_GetError());
SDL_Quit();

}

return surface;
}

// esta función dibuja el fondo en la pantalla
void dibujarFondo(SDL_Surface *screen, SDL_Surface *fondo) {
SDL_Rect rect;
rect.x = 0;
rect.y = 0;
SDL_BlitSurface(fondo, NULL, screen, &rect );
}
int main (int argc, char *argv[]) {

SDL_Event event;
SDL_Surface *screen, *fondo;
Uint8 *keystate; // variable que recoge el valor de la tecla pulsada

int done = 0;

if (SDL_Init(SDL_INIT_VIDEO) == -1) {
printf("No se pudo iniciar SDL: %s\n", SDL_GetError());
SDL_Quit();
return -1;
}

screen = SDL_SetVideoMode(640,480,16, SDL_SWSURFACE);

if(!screen){
printf("No se pudo iniciar la pantalla: %s\n", SDL_GetError());
SDL_Quit();
return -1;
}

// creamos el fondo
fondo = crearFondo();

// creamos el elemento
Elemento *nave = new Elemento();
nave->addFrame("ima.png");
nave->setX(300);
nave->setY(300);

while (done == 0) {

dibujarFondo(screen, fondo);
nave->dibujar(screen);
SDL_Flip(screen);

keystate = SDL_GetKeyState(NULL);
if ( keystate[SDLK_UP] && nave->getY()>0 ) nave->addY(-5);
if ( keystate[SDLK_DOWN] && nave->getY() < 410 ) nave->addY(5);
if ( keystate[SDLK_LEFT] && nave->getX()>0 ) nave->addX(-5);
if ( keystate[SDLK_RIGHT] && nave->getX() < 555) nave->addX(5);

// Comprobando teclas para opciones

while (SDL_PollEvent(&event)) {

// Cerrar la ventana
if (event.type == SDL_QUIT) { done = 1; }

// Pulsando una tecla
if (event.type == SDL_KEYDOWN) {
if (event.key.keysym.sym==SDLK_ESCAPE) {
done = 1;
}
}
}
}
SDL_Quit();
printf("\nTodo ha salido bien.\n");
return 0;
}
