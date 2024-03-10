/*  First repeated occurrence of either'a' or 'b' or 'c' or 'd'
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    bool found_a = false, found_b = false, found_c = false, found_d = false;
    bool found_repeated = false;
    char c;
    int count = -1;

    while (!found_repeated)
    {
        cin >> c;

        if (c == 'a')
        {
            if (found_a) found_repeated = true;
            else found_a = true;
        }
        else if (c == 'b')
        {
            if (found_b) found_repeated = true;
            else found_b = true;
        }
        else if (c == 'c')
        {
            if (found_c) found_repeated = true;
            else found_c = true;
        }
        else
        {
            if (found_d) found_repeated = true;
            else found_d = true;
        }

        ++count;
    }

    cout << c << " " << count << endl;
}