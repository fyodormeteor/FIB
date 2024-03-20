/*  Camí més llarg en un arbre
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "longestLeftmostPath.hh"
using namespace std;

BinTree<int> treeOfHeight(BinTree<int> t)
{
    // Base
    if (t.empty()) return BinTree<int>(0);

    // Recursivo
    BinTree<int> tleft = treeOfHeight(t.left());
    BinTree<int> tright = treeOfHeight(t.right());

    int hleft = tleft.value();
    int hright = tright.value();

    return BinTree<int>(1+max(hleft,hright), tleft, tright);
}

list<int> longestBlaBlaBlaAux(BinTree<int> t, BinTree<int>& th)
{
    // Base
    if (th.value() == 0) return list<int>();

    // Recursivo
    auto th_left = th.left();
    auto th_right = th.right();

    if (th.left().value() >= th.right().value())
    {
        list<int> l = longestBlaBlaBlaAux(t.left(), th_left);
        l.push_front(t.value());
        return l;
    }
    else
    {
        list<int> l = longestBlaBlaBlaAux(t.right(), th_right);
        l.push_front(t.value());
        return l;
    }
}

list<int> longestLeftmostPath(BinTree<int> t)
{
    BinTree<int> th = treeOfHeight(t);
    list<int> l = longestBlaBlaBlaAux(t, th);
    return l;
}