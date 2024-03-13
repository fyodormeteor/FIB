/*  Modificacio d'un BinTree de parells
    13.03.2024

    https://github.com/fyodormeteor
*/

#include "BinTree.hh"
#include "ParInt.hh"

void sumak(BinTree<ParInt>& a, int k)
{
    // Base
    if (a.empty()) return;
    
    // Recursive
    auto left_aux = a.left();
    auto right_aux = a.right();

    sumak(left_aux, k);
    sumak(right_aux, k);

    auto aux = BinTree<ParInt>(ParInt(a.value().primer(), a.value().segon() + k), left_aux, right_aux);
    a = aux;
}