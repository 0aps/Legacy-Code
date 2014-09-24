PBITMAPINFO CreateBitmapInfoStructure(HBITMAP hBmp)
{
	BITMAP bmp;
	PBITMAPINFO pbmi;
	WORD cClrBits;

	//obtiene la altura, anchura, y profundidad del color de la imagen
	if(!GetObject(hBmp,sizeof(BITMAP),(LPSTR)&bmp))return NULL;

	cClrBits = 24;

	/*
	reserva la memoria para la estructura PBITMAPINFO, que contendrá la informacion
	de la cabecera
	*/
	if(cClrBits!=24)
		pbmi=(PBITMAPINFO)LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*(1<<cClrBits));
	else
		pbmi=(PBITMAPINFO)LocalAlloc(LPTR,sizeof(BITMAPINFOHEADER));

	//inicializa la estructura
	pbmi->bmiHeader.biSize		= sizeof( BITMAPINFOHEADER );
	pbmi->bmiHeader.biWidth		= bmp.bmWidth;
	pbmi->bmiHeader.biHeight	= bmp.bmHeight;
	pbmi->bmiHeader.biPlanes	= bmp.bmPlanes;
	pbmi->bmiHeader.biBitCount	= 24;

	if(cClrBits<24)pbmi->bmiHeader.biClrUsed=(1<<cClrBits);

	pbmi->bmiHeader.biCompression	= BI_RGB;
	pbmi->bmiHeader.biSizeImage=(pbmi->bmiHeader.biWidth+7)/8*pbmi->bmiHeader.biHeight*cClrBits;
	pbmi->bmiHeader.biClrImportant	= 0;

	return pbmi;
}

HRESULT SaveBitmap(char strFileName[128],PBITMAPINFO pbi,HBITMAP hBMP,HDC hDC)
{
	HRESULT hr = E_FAIL;
	HANDLE hf;			// file handle
	BITMAPFILEHEADER hdr;		// bitmap file-header
	PBITMAPINFOHEADER pbih;		// bitmap info-header
	LPBYTE lpBits;		// memorypointer
	DWORD dwTotal;	// total count of bytes
	DWORD cb;			// incremental count of bytes
	BYTE *hp;		// byte pointer
	DWORD dwTmp;		// temp-variable


	if(pbi==NULL)return E_FAIL;

	pbih=(PBITMAPINFOHEADER)pbi;
	lpBits=(LPBYTE)GlobalAlloc(GMEM_FIXED,pbih->biSizeImage);

	if(!lpBits)return E_FAIL;

	if(!GetDIBits(hDC,hBMP,0,(WORD)pbih->biHeight,lpBits,pbi,DIB_RGB_COLORS))return E_FAIL;

	//crea el .bmp
	hf=CreateFile(strFileName,GENERIC_READ|GENERIC_WRITE,(DWORD)0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,(HANDLE)NULL);

	if(hf==INVALID_HANDLE_VALUE)return E_FAIL;

	hdr.bfType = 0x4D42;	// 0x42 = "B", 0x4D = "M"


	hdr.bfSize=(DWORD)(sizeof(BITMAPFILEHEADER)+pbih->biSize+pbih->biClrUsed*sizeof(RGBQUAD)+pbih->biSizeImage);
	hdr.bfReserved1=0;
	hdr.bfReserved2=0;

	hdr.bfOffBits=(DWORD)sizeof(BITMAPFILEHEADER)+pbih->biSize+pbih->biClrUsed*sizeof(RGBQUAD);


	if(!WriteFile(hf,(LPVOID)&hdr,sizeof(BITMAPFILEHEADER),(LPDWORD)&dwTmp,NULL))return E_FAIL;

	if(!WriteFile(hf,(LPVOID)pbih,sizeof(BITMAPINFOHEADER)+pbih->biClrUsed*sizeof(RGBQUAD),(LPDWORD)&dwTmp,(NULL)))return E_FAIL;


	dwTotal=cb=pbih->biSizeImage;
	hp=lpBits;

	if(!WriteFile(hf,(LPSTR)hp,(int)cb,(LPDWORD)&dwTmp,NULL))return E_FAIL;
	if(!CloseHandle(hf))return E_FAIL;

	GlobalFree((HGLOBAL)lpBits);

	return S_OK;
}

/*
uso: CapturaPantalla(posicion_inicial_x,posicion_inicial_y,posicion_final_x,posicion_final_y);
*/

void CapturaPantalla(unsigned int Ax,unsigned int Ay,unsigned int Bx,unsigned int By,char *Ruta)
{
	BYTE *mem;
	int bpp,c;
    HWND HwndSrc;
    HDC HdcSrc;
    HDC HdcMemory;
    HDC HdcStrech;
    HBITMAP Hbmp;
    HBITMAP HbmpStrech;
    HBITMAP HbmpPrev;
    HBITMAP HbmpPrevStrech;
    HBITMAP BmpPrueba;

	HwndSrc=GetDesktopWindow();                               //almacena el manejador del escritorio
    HdcSrc=GetWindowDC(HwndSrc);                               //se obtiene el DC del escritorio
	HdcMemory=CreateCompatibleDC(HdcSrc);                      //se crea una copia del DC del escritorio
	HdcStrech=CreateCompatibleDC(HdcSrc);                   //Cd que almacenara la imagen pequeña
	Hbmp=CreateCompatibleBitmap(HdcSrc,1024,768);          //se cra un bitmap del DC del escritorio
	HbmpStrech=CreateCompatibleBitmap(HdcSrc,Bx-Ax,By-Ay);  //bitmap que almacenara el Strech
	HbmpPrev=(HBITMAP)SelectObject(HdcMemory,Hbmp);        //se asocia el bitmap con el DC
	HbmpPrevStrech=(HBITMAP)SelectObject(HdcStrech,HbmpStrech);

	BitBlt(HdcMemory,0,0,800,600,HdcSrc,Ax,Ay,SRCCOPY);
    StretchBlt(HdcStrech,0,0,800,600,HdcMemory,0,0,800,600,SRCCOPY);
    HbmpStrech=(HBITMAP)SelectObject(HdcStrech,HbmpPrevStrech);
    Hbmp=(HBITMAP)SelectObject(HdcMemory,HbmpPrev);

	bpp=800*600*8;

	c=GetBitmapBits(HbmpStrech,0,0);
	mem=(BYTE*)malloc((c-1)*sizeof(BYTE*));
	memset(mem,0,sizeof(mem));

    GetBitmapBits(HbmpStrech,c,mem);
	BmpPrueba = CreateCompatibleBitmap(HdcSrc,Bx-Ax,By-Ay);
	SetBitmapBits(BmpPrueba,c,mem);
	SaveBitmap(Ruta,CreateBitmapInfoStructure(BmpPrueba),BmpPrueba,HdcSrc);

    DeleteDC(HdcSrc);
    DeleteDC(HdcMemory);
    DeleteDC(HdcStrech);
    DeleteObject(Hbmp);
    DeleteObject(HbmpPrev);
    DeleteObject(HbmpStrech);
    DeleteObject(HbmpPrevStrech);

	return;
}
