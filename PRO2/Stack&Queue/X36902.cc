/*  Avaluacio d'una expressio amb parentesis
    28.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> s;
    char c;

    int pos = 0;
    int length = 0;
    bool wrong = false;

    while(cin >> c and c != '.')
    {
        switch (c)
        {
            case '(':
            case '[':
                s.push(c);
            break;

            case ')':
                if (!s.empty() and s.top() == '(') s.pop();
                else wrong = true;
            break;

            case ']':
                if (!s.empty() and s.top() == '[') s.pop();
                else wrong = true;
            break;
            
            default: break;
        }

        if (!wrong) pos++;
        length++;
    }

    if (s.size() > 0)
    {
        wrong = true;

        if (pos == length) pos--;
    }

    if (wrong)
    {
        cout << "Incorrecte " << pos+1 << endl; 
    }
    else cout << "Correcte" << endl;
}   