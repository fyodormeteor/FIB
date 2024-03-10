/*  Recursive pattern with closure
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;
 
const char c = '*';

// Pre: n >= 1
void recursive_draw(const int n)
{
    if (n == 1)
    {
        cout << c << endl;
    }
    else
    {
        for(int i = 0; i < n; ++i)
            cout << c;
        cout << endl;

        recursive_draw(n-1);
        recursive_draw(n-1);
        recursive_draw(n-1);

        for(int i = 0; i < n; ++i)
            cout << c;
        cout << endl;
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        recursive_draw(n);
        cout << endl;
    }
}