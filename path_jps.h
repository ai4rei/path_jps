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
    size_t count;  /* actual amount of points in the structure */
    int16 x[MAX_WALKPATH2];
    int16 y[MAX_WALKPATH2];
};

/**
    @brief  Looks for a path between points (x0,y0) and (x1,y1).
    @param  wpd
            Pointer to a structure that receives the path points, if
            one is found. If the path is longer than MAX_WALKPATH2
            the call will fail.
    @param  m
            Map-index.
    @param  x0
            X-coordinate of the start point.
    @param  y0
            Y-coordinate of the start point.
    @param  x1
            X-coordinate of the end point.
    @param  y1
            Y-coordinate of the end point.
    @param  flag
            Reserved, set to zero.
    @param  limit
            0: No limit
            N: Perform only N steps before giving up.
    @param  step
            0: Record only way-points.
            1: Record every step.
            N: Record every Nth step.
    @param  cell
            One of the CELL_CHK* constants to determine the type of
            collision testing.
    @return true
            Path was found and saved.
    @return false
            Path was not found or it was too long.
*/
bool path_search_jps(struct walkpath_data2* wpd, const int16 m, const int16 x0, const int16 y0, const int16 x1, const int16 y1, int flag, int limit, unsigned int step, cell_chk cell);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _PATH_JPS_H_ */
