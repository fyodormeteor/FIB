/*  Arbre de sumes d'ancestres
    26.03.2024

    Fichero a entregar: treeOfSumsOfAncestors.cc

    https://github.com/fyodormeteor
*/

#include <list>

using namespace std;

#include "treeOfSumsOfAncestors.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        BT r = treeOfSumsOfAncestors(t);
        r.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << r << endl;
	}
}
