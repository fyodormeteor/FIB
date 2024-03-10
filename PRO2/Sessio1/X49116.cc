/*  Maxim i minim d'un vector (no main)
    14.02.2024

    https://github.com/fyodormeteor
*/

#include <vector>
using namespace std;
 
struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint ret;

    ret.prim = v[0];
    ret.seg = v[0];

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > ret.prim) ret.prim = v[i];
        if (v[i] < ret.seg) ret.seg = v[i];
    }

    return ret;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int,int> ret;

    ret.first = v[0];
    ret.second = v[0];

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > ret.first) ret.first = v[i];
        if (v[i] < ret.second) ret.second = v[i];
    }

    return ret;
}
 
void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = v[0];
    y = v[0];

    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}