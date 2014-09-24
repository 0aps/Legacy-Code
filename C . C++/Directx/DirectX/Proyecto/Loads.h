bool bMenu = false; // Is Menu Shown?
bool runOnce = true; // Needed for a few things Only well Run Once
LPD3DXFONT        pFont; // Font Object
D3DVIEWPORT9    pViewPort; // Viewport so we can align everything up

LPDIRECT3DTEXTURE9 TexMenu, TexCursor, TexNorm, TexActive; // Base part of menu, The Cursor, (Norm/Active) buttons
LPD3DXSPRITE SptMenu; // Sprite for rendering
// Text Colors
#define tGreen  D3DCOLOR_ARGB( 255,   0, 255,   0 )
#define tRed    D3DCOLOR_ARGB( 255, 255, 0, 0 )
#define tBlue    D3DCOLOR_ARGB( 255,    0,    0,    255)
#define tYellow    D3DCOLOR_ARGB( 255,    255, 255, 0)
#define tBlack    D3DCOLOR_ARGB( 255, 0, 0, 0)
#define tWhite    D3DCOLOR_ARGB( 255, 255, 255, 255)
#define tOrange D3DCOLOR_ARGB( 255, 250, 191, 143)  
