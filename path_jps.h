#ifndef _PATH_JPS_H_
#define _PATH_JPS_H_

#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */

#include "map.h"  /* enum cell_chk */

#define MAX_WALKPATH2 32

struct walkpath_data2
{
    size_t count;
    int16 x[MAX_WALKPATH2];
    int16 y[MAX_WALKPATH2];
};

bool path_search_jps(struct walkpath_data2* wpd, const int16 m, const int16 x0, const int16 y0, const int16 x1, const int16 y1, int flag, cell_chk cell);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _PATH_JPS_H_ */
