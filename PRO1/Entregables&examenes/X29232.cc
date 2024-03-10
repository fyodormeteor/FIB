/*  Given four integers, check that two of them are equal
    and the other two are different
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int count = 0;

    if (a == b) count++;
    if (a == c) count++;
    if (a == d) count++;
    if (b == c) count++;
    if (b == d) count++;
    if (d == c) count++;

    if (count == 1) cout << "YES";
    else            cout << "NO";
    cout << endl;
}