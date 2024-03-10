/*  Uppercase and lowercase letters
    14.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    char c;
    char out;
    cin >> c;

    if (c >= 'A' and c <= 'Z')
    {
        out = int(c) + int('a') - int('A');
    }
    else out = int(c) - int('a') + int('A');

    cout << out << endl;
}