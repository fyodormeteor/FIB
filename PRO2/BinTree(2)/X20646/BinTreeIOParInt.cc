/*  Cerca en un BinTree de parells d'enters
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "BinTreeIOParInt.hh"
#include <iostream>
#include <string>

void read_bintree_parint(BinTree<ParInt>& a)
{
    ParInt root;
    
    // Base
    if (!root.llegir())
    {
        a = BinTree<ParInt>();
        return;
    }

    // Recursivo
    BinTree<ParInt> left;
    BinTree<ParInt> right;

    read_bintree_parint(left);
    read_bintree_parint(right);

    a = BinTree<ParInt>(root, left, right);
}