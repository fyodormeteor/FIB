/*  Cerca en una llista de parells d'enters 
    06.03.2024

    https://github.com/fyodormeteor
*/

#include "ParInt.hh"
#include "LlistaIOParInt.hh"

using namespace std;

int main()
{
    list<ParInt> l;
    LlegirLlistaParInt(l);

    int n;
    cin >> n;
    int count, sum;
    count = sum = 0;

    for (list<ParInt>::iterator it = l.begin(); it != l.end(); it++)
    {
        ParInt p = *it;
        
        if (p.primer() == n)
        {
            count++;
            sum += p.segon();
        }
    }

    cout << n << ' ' << count << ' ' << sum << endl;
}