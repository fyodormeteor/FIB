/*  Counting a's (2)
    05.10.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    char c = ' ';
    int count = 0;
    while (c != '.')
    {
        cin >> c;
        if (c == 'a') ++count;
    }
    cout << count << endl;
}