/*  Suma dels valors d'un arbre 
    13.03.2024

    Fichero a entregar: sumOfTree.cc

    https://github.com/fyodormeteor
*/

#include "sumOfTree.cc"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BinTree<int> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << sumOfTree(t) << endl;
  	}
}
