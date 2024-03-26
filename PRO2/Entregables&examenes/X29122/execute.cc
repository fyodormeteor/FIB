/*  Executar assignació, print, if i while
    26.03.2024

    https://github.com/fyodormeteor
*/

#include "execute.hh"
using namespace std;

int evaluate(map<string,int> &var2val, BinTree<string> t)
{
    // Base
    if (t.empty()) return 0;

    // Recursive
    string root = t.value();
    if (root == "+")
    {
        int ret = evaluate(var2val, t.left()) + evaluate(var2val, t.right());
        ret = ret%10;
        return ret;
    }
    if (root == "*") 
    {
        int ret = evaluate(var2val, t.left()) * evaluate(var2val, t.right());
        ret = ret%10;
        return ret;
    }
    if (root[0] - int('0') >= 0 and root[0] - int('0') <= 9 and root.size() == 1) // Checks if root is a number
    {
        return root[0] - int('0');
    }

    // Doesn't satisfy any of the above implies root is a variable
    return var2val[root];

}

void execute(map<string,int> &var2val, BinTree<string> t)
{
    // Base
    if (t.empty()) return;

    // Recursive
    string root = t.value();
    if (root == "=")
    {
        string variable = t.left().value();
        int value = evaluate(var2val, t.right());

        var2val[variable] = value;
    }
    else if (root == "if")
    {
        int evaluation = evaluate(var2val, t.left());
        if (evaluation != 0)
        {
            execute(var2val, t.right());
        }
    }
    else if (root == "while")
    {
        int evaluation = evaluate(var2val, t.left());
        while (evaluation != 0)
        {
            execute(var2val, t.right());
            evaluation = evaluate(var2val, t.left());
        }
    }
    else if (root == "list")
    {
        execute(var2val, t.left());
        execute(var2val, t.right());
    }
    else // Doesn't satisfy any of the above implies root == print
    {
        int evaluation = evaluate(var2val, t.left());
        cout << evaluation << endl;
    }
}
