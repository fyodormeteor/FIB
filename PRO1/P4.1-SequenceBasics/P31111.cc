/*  Parentheses
    28.09.2023

    https://github.com/fyodormeteor
*/

#include <iostream>
using namespace std;

int main()
{
    char c;
    int open = 0;
    bool b = true;
    while(cin >> c)
    {
        if (c == '(')   ++open;
        else            --open;

        if (open < 0)
        {
            b = false;
            break;
        }
    }
    if (b and open == 0)    cout << "yes";
    else                    cout << "no";
    cout << endl;          
}