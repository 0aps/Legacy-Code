#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

//BUILDING_DLL
// opcion que la agrega el compilador por default = 1 siempre

//las funciones se declaran como exportadas
//hacia afuera

class DLLIMPORT DllClass
{
  public:
    DllClass();
    virtual ~DllClass(void);

  private:

};


#endif /* _DLL_H_ */
