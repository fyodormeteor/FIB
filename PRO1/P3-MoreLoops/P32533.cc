/*  Control C202E
    28.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int j;

    for (int i = 0; i < n; ++i)
    {
        j = 0;
        while (j < n-i-1)
        {
            cout << '+';
            ++j;
        }
        cout << '/';
        j = 0;
        while (j < i)
        {
            cout << '*';
            ++j;
        }
        cout << endl;
    }
}