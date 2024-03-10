/*  Recursivitat alterna
    21.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<cmath>
using namespace std;

const char c = '*';
const char s = ' ';

void deduce(int n, int shift)
{
    //base
    if (n == 0)
    {
        for(int i = 0; i < shift; ++i)
        {
            cout << s;
        }
        cout << c << endl;
    }
    //recursive
    else
    {
        int extra_shift = pow(2, n-1);
        if (n%2 == 0)
        {
            deduce(n-1, shift);
            deduce(n-1, shift+extra_shift);
        }
        else
        {
            deduce(n-1, shift+extra_shift);
            deduce(n-1, shift);
        }
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        deduce(n, 0);
        cout << "----------" << endl;
    }
    
}