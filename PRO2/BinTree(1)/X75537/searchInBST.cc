/*  Cerca en un BST (arbre de cerca binaria)
    13.03.2024

    https://github.com/fyodormeteor
*/

#include "searchInBST.hh"

bool searchInBST(BinTree<int> t, int x)
{
    // Base
    if (t.empty()) return false;
    if (t.value() == x) return true;

    // Recursive
    if (t.value() < x) // x might be in t.right()
    {
        return searchInBST(t.right(), x);
    }
    if (t.value() > x) // x might be in t.left()
    {
        return searchInBST(t.left(), x);
    }

    return false; // Code will never reach here
}