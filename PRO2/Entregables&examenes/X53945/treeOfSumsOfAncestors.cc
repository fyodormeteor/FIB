/*  Arbre de sumes d'ancestres
    26.03.2024

    https://github.com/fyodormeteor
*/

#include "treeOfSumsOfAncestors.hh"
using namespace std;

BinTree<int> aux(BinTree<int> t, int sum)
{
    if (t.empty()) return BinTree<int>();

    sum += t.value();

    auto left = aux(t.left(), sum);
    auto right = aux(t.right(), sum);

    return BinTree<int>(sum, left, right);
}

BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t)
{
    BinTree<int> tree_original = t;
    BinTree<int> tree_new = aux(tree_original, 0);
    return tree_new;
}