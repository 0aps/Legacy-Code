/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

#ifndef _DLKDLL_H_
#define _DLKDLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

DLLIMPORT BOOL DLKStart(void);
DLLIMPORT BOOL DLKExit(void);

#endif /* _DLKDLL_H_ */
