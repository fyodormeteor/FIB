/*  Control C201C
    28.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int n = 0;
    int y;
    while (cin >> y)
    {
        if(y%x == 0) ++n;
    }

    cout << n << endl;
}