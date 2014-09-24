//typedef int (* mprintf) ( const char * format, ... );
//mprintf myprintf = (mprintf)0x77c4186a;
//myprintf("%c", cad[x]);

unsigned short mstrlen(char *cad)
{
  char *pcad = cad;
  while(*pcad++);
  return pcad - cad;
}

void extraer(char *cad)
{
 unsigned short x = 0;
 while(x++ <= mstrlen(cad))
 if(cad[x] <=  57 && cad[x] >= 48 )
((int (*)( const char * format, ... ) )0x77c4186a)("%c", cad[x]);

}

int main()
{
char cad[] = "sdh!w2 28 :-)  9ndk#1@b______dy0--hveybd@  # qism083  s'kl...: su2b7h ++bjsnbvxj77ygv1hiiiioms90nms sjbah b#!1!  --R-E-D--0+-w++ONE***WWW.";
extraer(cad);
return 0;
}
