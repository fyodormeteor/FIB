/*  Suma dels valors d'un arbre a profunditat parell
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "sumAtDepthEven.hh"

using namespace std;

int sumAtDepthEven(BinTree<int> t)
{
    // Base
    if (t.empty()) return 0;

    // Recursive
    int sum = t.value();
    if (!t.left().empty())
    {
        sum += sumAtDepthEven(t.left().left());
        sum += sumAtDepthEven(t.left().right());
    }
    if (!t.right().empty())
    {
        sum += sumAtDepthEven(t.right().left());
        sum += sumAtDepthEven(t.right().right());
    }
    return sum;
}