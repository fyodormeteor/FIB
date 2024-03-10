/*  Chess board (1)
    28.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    char digit;
    int sum = 0;

    for(int i = 0; i < r*c; ++i)
    {
        cin >> digit;
        sum += int(digit) - int('0');
    }

    cout << sum << endl;
}
