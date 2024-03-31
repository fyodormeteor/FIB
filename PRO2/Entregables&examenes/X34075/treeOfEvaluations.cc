/*  Arbre d'avaluacións d'expressió booleana
    31.03.2024

    https://github.com/fyodormeteor
*/

#include "treeOfEvaluations.hh"

BinTree<bool> treeOfEvaluations(BinTree<string> t)
{
    // Base
    if (t.empty()) return BinTree<bool>();
    if (t.value() == "true") return BinTree<bool>(true);
    if (t.value() == "false") return BinTree<bool>(false);

    // Recursive
    BinTree<bool> left = treeOfEvaluations(t.left());
    BinTree<bool> right = treeOfEvaluations(t.right());

    bool eval = false;

    if (t.value() == "and")
    {
        eval = (left.value() and right.value());
    }
    else if (t.value() == "or")
    {
        eval = (left.value() or right.value());
    }
    else
    {
        eval = !left.value();
    }

    return BinTree<bool>(eval, left, right);
}