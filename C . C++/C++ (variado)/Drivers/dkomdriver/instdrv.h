#ifndef __INSTDRV_H__
#define __INSTDRV_H__

#define IS_WINDOWS_NT   11
#define IS_WINDOWS_2000 21
#define IS_WINDOWS_XP   31
#define IS_WINDOWS_2003 41
#define NOT_SUPPORTED   0

#define VERBOSE_ON  1
#define VERBOSE_OFF 0

typedef struct typeProcess{
   int iPid;
   struct typeProcess *next;
}pProcessElement;

#endif //__INSTDRV_H__
