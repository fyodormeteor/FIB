/*  Nombre de bessons (parelles de nodes germans amb el mateix valor)
    09.04.2024

    https://github.com/fyodormeteor
*/

#include "numTwins.hh"

// Pre:
// Post: Retorna el nombre de parelles de nodes de t que tenen el mateix node pare i el mateix valor
int numTwins(BinTree<int> t)
{
    // Base
    if (t.empty())
    {
        return 0;
    }
    // Recursive
    int sum = 0;
    sum += numTwins(t.left());
    sum += numTwins(t.right());
    if (!t.left().empty() and !t.right().empty() and t.left().value() == t.right().value())
    {
        sum += 1;
    }
    return sum;
}