/*  Avaluar expressions sense variables
    13.03.2024

    Fichero a entregar: evaluate.cc

    https://github.com/fyodormeteor
*/

#include "evaluate.hh"

int main()
{
    string format;
    getline(cin, format);
    BinTree<string> t;
    t.setInputOutputFormat(format=="INLINEFORMAT"?BinTree<string>::INLINEFORMAT:BinTree<string>::VISUALFORMAT);
    while (cin >> t and not t.empty()) {
    	cout << evaluate(t) << endl;
  	}
}