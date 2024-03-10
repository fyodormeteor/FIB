/*  Control C101A
    14.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int n0, n1, n2;
    n2 = n/100;
    n = n%100;
    n1 = n/10;
    n = n%10;
    n0 = n;

    n2 = n2%10;
    
    cout << n0+n1+n2 << endl;
}