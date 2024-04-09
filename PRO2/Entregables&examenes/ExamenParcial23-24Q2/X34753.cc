/*  Arbre amb inordre
    09.04.2024

    https://github.com/fyodormeteor
*/

#include "inorderTree.hh"

BinTree<int> auxiliarInorderTree(BinTree<int> t, int& current) // Recursive auxiliary function
{
    //Base
    if (t.empty())
    {
        return BinTree<int>();
    }

    // Recursive
    auto t_left = auxiliarInorderTree(t.left(), current);
    int my_pos = ++current;
    auto t_right = auxiliarInorderTree(t.right(), current);

    return BinTree<int>(my_pos, t_left, t_right);
}

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a parÃ metre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en inordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> inorderTree(BinTree<int> t) // Calls auxiliary function
{
    int current = 0;
    BinTree<int> result = auxiliarInorderTree(t, current);
    return result;
}