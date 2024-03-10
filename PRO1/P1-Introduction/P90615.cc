/*  Maximum of three integer numbers
    14.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int out = max(max(a,b),c);
    cout << out << endl;
}