/*  Comparing results of operations
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int num1, num2, num3;
    char op;
    string comp;

    while(cin >> num1 >> op >> num2 >> comp >> num3)
    {
        int num1_2;
        bool expr;

        if      (op == '+') num1_2 = num1 + num2;
        else if (op == '-') num1_2 = num1 - num2;
        else                num1_2 = num1 * num2;

        if      (comp == "<")     expr = (num1_2 < num3);
        else if (comp == ">")     expr = (num1_2 > num3);
        else if (comp == "<=")    expr = (num1_2 <= num3);
        else if (comp == ">=")    expr = (num1_2 >= num3);
        else if (comp == "==")    expr = (num1_2 == num3);
        else                      expr = (num1_2 != num3);
        
        if (expr) cout << "true";
        else cout << "false";
        cout << endl;
    }
}