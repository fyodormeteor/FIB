/*  Avaluar expressions amb variables 
    20.03.2024

    https://github.com/fyodormeteor
*/

#include "evaluate.hh"
#include "utils.hh"

using namespace std;

int evaluate(map<string,int> &variable2value, BinTree<string> t)
{
    // Base
    if (t.empty()) return 0;

    // Recursivo
    string value = t.value();
    if (isNumber(value)) return mystoi(value);
    if (isVariable(value)) return variable2value[value];

    if (value == "*") return evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
    if (value == "+") return evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
    if (value == "-") return evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());

    return -1; // Codigo nunca llegara aqui si se cumple PRE
}