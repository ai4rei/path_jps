#if _MSC_VER <= 1600

namespace std
{
    template< typename T > const T& min(const T& One, const T& Two)
    {
        if(One<Two)
        {
            return One;
        }

        return Two;
    }
    template< typename T > const T& max(const T& One, const T& Two)
    {
        if(One<Two)
        {
            return Two;
        }

        return One;
    }
}

#endif  /* _MSC_VER <= 1600 */

#include "JPS.h"

#include "path_jps.h"

class CCellChk
{
private:
    struct map_data* m_md;
    cell_chk m_cell;

public:
    CCellChk(struct map_data* md, cell_chk cell) : m_md(md), m_cell(cell)
    {
        ;
    }

    inline bool operator()(const int16 x, const int16 y) const
    {
        return map_getcellp(m_md, x, y, m_cell)==0;
    }
};

bool path_search_jps(struct walkpath_data2* wpd, const int16 m, const int16 x0, const int16 y0, const int16 x1, const int16 y1, int flag, cell_chk cell)
{
    struct map_data* md = &map[m];

    if(md->cell==NULL)
    {
        return false;
    }

    if(x0<0 || x0>=md->xs || y0<0 || y0>=md->ys)
    {
        return false;
    }

    if(x1<0 || x1>=md->xs || y1<0 || y1>=md->ys || map_getcellp(md, x1, y1, cell))
    {
        return false;
    }

    CCellChk grid(md, cell);
    JPS::PathVector path;

    if(JPS::findPath(path, grid, x0, y0, x1, y1, 0 /* 0 = waypoints, 1 = every point, N = every Nth point */))
    {
        if(wpd)
        {
            if(path.size()<=ARRAYLENGTH(wpd->x))
            {
                size_t idx = 1;

                // path does not include the start point
                wpd->x[0] = x0;
                wpd->y[0] = y1;

                for(JPS::PathVector::iterator it = path.begin(); it!=path.end(); it++)
                {
                    wpd->x[idx] = it->x;
                    wpd->y[idx] = it->y;

                    idx++;
                }

                wpd->count = idx;

                return true;
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}
