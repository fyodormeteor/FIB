/*  Completely parenthesed expression
    21.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int evalExpression()
{
    char c;
    cin >> c;

    int e1;
    int e2;

    if (int(c) >= int('0') and int(c) <= int('9'))
    {
        return int(c) - int('0');
    }
    else
    {
        e1 = evalExpression();
        char op;
        char ajhsdgas;
        cin >> op;
        e2 = evalExpression();
        cin >> ajhsdgas;
        if (op == '+') return e1+e2;
        if (op == '-') return e1-e2;
        return e1*e2;
    }
}

int main()
{
    cout << evalExpression() << endl;
}