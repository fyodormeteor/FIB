/*  Given three numbers, check if one of them equals the average of the other two
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    bool found = false;
    cin >> a >> b >> c;

    if      ((b+c)/2.0 == a) found = true;
    else if ((a+c)/2.0 == b) found = true;
    else if ((a+b)/2.0 == c) found = true;

    if (found) cout << "YES";
    else cout << "NO";
    cout << endl;
}