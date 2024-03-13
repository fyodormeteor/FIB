/*  Avaluar expressions sense variables
    13.03.2024

    https://github.com/fyodormeteor
*/

#include "evaluate.hh"
#include "utils.hh"

int evaluate(BinTree<string> t)
{
    // Base
    if (t.empty()) return 0;
    if (isNumber(t.value())) return mystoi(t.value());

    // Recursive
    if (t.value() == "+")
    {
        return evaluate(t.left()) + evaluate(t.right());
    }
    if (t.value() == "-")
    {
        return evaluate(t.left()) - evaluate(t.right());
    }
    return evaluate(t.left()) * evaluate(t.right());
}