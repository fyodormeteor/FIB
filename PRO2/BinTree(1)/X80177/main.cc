/*  Arbre revessat
    13.03.2024

    Fichero a entregar: reverseTree.cc

    https://github.com/fyodormeteor
*/

#include "reverseTree.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        t = reverseTree(t);
        t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << t << endl;
  	}
}
