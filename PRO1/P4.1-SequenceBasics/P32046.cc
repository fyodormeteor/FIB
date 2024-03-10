/*  Control C202F
    05.10.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    cout << "nombres que acaben igual que " << x << ':' << endl;

    int y = 0;

    y += x%10;
    x /= 10;
    y += (x%10)*10;
    x /= 10;
    y += (x%10)*100;

    int count = 0;
    while(cin >> x)
    {
        if (x%1000 == y)
        {
            cout << x << endl;
            ++count;
        }
    }

    cout << "total: " << count << endl;
}