/*  Suma dels valors d'un arbre 
    13.03.2024

    https://github.com/fyodormeteor
*/

#include <iostream>

using namespace std;

#include "BinTree.hh"

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinTree<int> t)
{
    // Base
    if (t.empty()) return 0;
    // Recursive
    int sum = t.value();
    sum += sumOfTree(t.left());
    sum += sumOfTree(t.right());
    return sum;
}
