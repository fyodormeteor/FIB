/*  Suma dels valors d'un arbre a profunditat parell
    20.03.2024

    Fichero a entregar: sumAtDepthEven.cc

    https://github.com/fyodormeteor
*/

#include "sumAtDepthEven.hh"

typedef BinTree<int> BT;

int main()
{
    string format;
    getline(cin, format);
    BT t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?  BT::INLINEFORMAT  :  BT::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    cout << sumAtDepthEven(t) << endl;
  }
}
