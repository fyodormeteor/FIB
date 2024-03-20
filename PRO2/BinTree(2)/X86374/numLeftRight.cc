/*  Nombre d'esquerra i dreta en un arbre binari
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "numLeftRight.hh"
using namespace std;

BinTree<int> numLeftRightAux(BinTree<int> t, int nl, int nr)
{  
    // Base
    if (t.empty()) return BinTree<int>();

    // Recursivo
    auto left = numLeftRightAux(t.left(), nl+1, nr);
    auto right = numLeftRightAux(t.right(), nl, nr+1);

    if (t.value() == -1)
    {
        return BinTree<int> (nl, left, right);
    }
    if (t.value() == -2)
    {
        return BinTree<int> (nr, left, right);
    }
    return BinTree<int>(); // Codigo nunca llegara aqui si se cumple PRE
}

BinTree<int> numLeftRight(BinTree<int> t)
{  
    BinTree<int> b = numLeftRightAux(t, 0, 0);
    return b;
}