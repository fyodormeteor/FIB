/*  Distribucio justa de cues
    28.02.2024

    https://github.com/fyodormeteor
*/

#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
    int n1, n2;
    while(cin >> n1 >> n2 and !(n1 == 0 and n2 == 0))
    {
        c.push(ParInt(n1, n2));
    }
}

void escriureCuaParInt(queue<ParInt> c)
{
    while (!c.empty())
    {
        cout << c.front().primer() << ' ' << c.front().segon() << endl;
        c.pop();
    }
}