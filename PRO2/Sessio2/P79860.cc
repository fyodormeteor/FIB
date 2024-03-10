/*  Bars (2)
    21.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

void deduce(int n)
{
    //base
    if (n == 1)
    {
        cout << '*' << endl;
    }
    // recursive
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << '*';
        }
        cout << endl;

        deduce(n-1);
        deduce(n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    deduce(n);
}