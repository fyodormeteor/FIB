/*  Prefixed expression (2)
    16.11.2023
    
    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int func()
{
    char c;
    cin >> c;

    if      (c == '+') return func() + func();
    else if (c == '-') return func() - func();
    else if (c == '*') return func() * func();
    else               return int(c) - int('0');
}

int main()
{
    cout << func() << endl;
}