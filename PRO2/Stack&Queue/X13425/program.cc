/*  Distribucio justa de cues
    28.02.2024

    https://github.com/fyodormeteor
*/

#include "CuaIOParInt.hh" 

int main()
{
    queue<ParInt> q1;
    queue<ParInt> q2;

    int time1, time2;
    time1 = time2 = 0;

    queue<ParInt> q;
    llegirCuaParInt(q);

    while(!q.empty())
    {
        if (time1 <= time2)
        {
            time1 += q.front().segon();
            q1.push(q.front());
        }
        else
        {
            time2 += q.front().segon();
            q2.push(q.front());
        }
        
        q.pop();
    }

    escriureCuaParInt(q1);
    cout << endl;
    escriureCuaParInt(q2);
}