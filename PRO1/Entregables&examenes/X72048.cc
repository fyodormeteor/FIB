/*  Recursive words
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
using namespace std;

string recursive(int d)
{
    if (d == 0) return "0";
    else 
    {
        string str = "";
        char c = char(int('0') + d);

        for(int i = 0; i < d; ++i)
        {
            str += c;
            str += recursive(d-1);
        }
        str += c;

        return str;
    }
}

int main()
{
    int d;
    while(cin >> d)
    {
        cout << recursive(d) << endl;
    }
}