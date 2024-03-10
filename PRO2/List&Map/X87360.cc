/*  Interseccio de llistes ordenades
    06.03.2024

    https://github.com/fyodormeteor
*/

#include<list>

using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos)
{
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();

    while(it1 != uno.end() and it2 != dos.end())
    {
        if (*it1 < *it2)
        {
            list<int>::iterator itc = it1;
            it1++;
            uno.erase(itc);
        }
        else if (*it1 == *it2)
        {
            it1++;
            it2++;
        }
        else
        {
            it2++;
        }
    }

    if (it2 == dos.end())
    {
        while (it1 != uno.end())
        {
            list<int>::iterator itc = it1;
            it1++;
            uno.erase(itc);
        }
    }
}
