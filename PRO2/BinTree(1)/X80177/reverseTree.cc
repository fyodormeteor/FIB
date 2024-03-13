/*  Arbre revessat
    13.03.2024

    https://github.com/fyodormeteor
*/

#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t)
{
    // Base
    if (t.empty()) return t;

    // Recursive
    t = BinTree<int>(t.value(), reverseTree(t.right()), reverseTree(t.left()));
    return t;
}