/*  Number of c's with an a before and without b between,
    and number of d's with an a after and without b between
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int satisfying_c = 0, satisfying_d = 0;
    int count_c = 0, count_d = 0;
    char ch;
    while (cin >> ch)
    {
        if (ch == 'a')
        {
            count_c = 1;
            satisfying_d += count_d;
            count_d = 0;
        }
        else if (ch == 'b')
        {
            count_c = 0;
            count_d = 0;
        }
        else if (ch == 'c')
        {
            satisfying_c += count_c;
        }
        else
        {
            count_d++;
        }
    }

    cout << satisfying_c << ' ' << satisfying_d << endl;
}