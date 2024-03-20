/*  Cerca en una llista de parells d'enters 
    06.03.2024

    https://github.com/fyodormeteor
*/

#include "LlistaIOParInt.hh"
#include <iostream>
#include <list>

void LlegirLlistaParInt(list<ParInt>& l)
{
    int a,b;
    while(cin >> a >> b and !(a == 0 and b == 0))
    {
        l.emplace_back(a, b);
    }
}

void EscriureLlistaParInt(const list<ParInt>& l); //(opcional)
