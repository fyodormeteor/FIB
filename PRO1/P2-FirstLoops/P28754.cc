/*  Reversed number in binary
    28.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int b = 2;

    if (n==0) cout << n;
    while (n > 0)
    {
        cout << n%b;
        n /= b;
    }  
    cout << endl;
}