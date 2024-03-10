/*  Control C102A
    14.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int x,a,b,c,d;
    cin >> x >> a >> b >> c >> d;

    if (((x>=a) && (x<=b)) || ((x>=c) && (x<=d)))
    {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}