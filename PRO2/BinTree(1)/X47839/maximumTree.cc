/*  Arbre maxim
    13.03.2024

    https://github.com/fyodormeteor
*/

#include "maximumTree.hh"

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2)
{
    // Base
    if (a1.empty() and a2.empty()) return BinTree<int>();
    if (a2.empty()) return a1;
    if (a1.empty()) return a2;

    // Recursive
    if (a1.value() >= a2.value())   return BinTree<int>(a1.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
    else                            return BinTree<int>(a2.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
}