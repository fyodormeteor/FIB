/*  Cerca en un BinTree de parells d'enters
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "BinTreeIOParInt.hh"
#include "ParInt.hh"
#include "BinTree.hh"
using namespace std;

// Pre: True
// Post: primer() = valor buscado, segon() = profundidad del valor
ParInt search_bintree_parint(BinTree<ParInt>& tree, const int search, int depth)
{
    if (tree.empty()) return ParInt(-1, 0);
    if (tree.value().primer() == search) return ParInt(tree.value().segon(), depth);

    BinTree<ParInt> tree_left = tree.left();
    BinTree<ParInt> tree_right = tree.right();

    ParInt left = search_bintree_parint(tree_left, search, depth+1);
    ParInt right = search_bintree_parint(tree_right, search, depth+1);

    if (left.primer() != -1)
    {
        return left;
    }
    if (right.primer() != -1)
    {
        return right;
    }
    return ParInt(-1, 0);
}

int main()
{
    BinTree<ParInt> tree;
    read_bintree_parint(tree);

    int search;
    while (cin >> search)
    {
        ParInt ret = search_bintree_parint(tree, search, 0);

        if (ret.primer() != -1)
        {
            cout << search << ' ' << ret.primer() << ' ' << ret.segon() << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}