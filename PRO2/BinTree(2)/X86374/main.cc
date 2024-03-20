/*  Nombre d'esquerra i dreta en un arbre binari
    20.03.2024

    Fichero a entregar: numLeftRight.cc

    https://github.com/fyodormeteor
*/

#include "numLeftRight.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
        BT r = numLeftRight(t);
        r.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
        cout << r << endl;
  	}
}