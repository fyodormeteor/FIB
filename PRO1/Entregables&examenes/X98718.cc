/*  First repeated subword of size 3
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    bool found_aaa = false, found_aab = false, found_aba = false, found_abb = false;
    bool found_baa = false, found_bab = false, found_bba = false, found_bbb = false;
    bool found_repeated = false;
    char char0 = 'x', char1 = 'x', char2 = 'x';
    int count = 0;

    while (!found_repeated)
    {
        char2 = char1;
        char1 = char0;
        cin >> char0;

        if (char2 == 'a')
        {
            if (char1 == 'a')
            {
                if (char0 == 'a')
                {
                    /// aaa
                    if (found_aaa) found_repeated = true; else found_aaa = true;
                }
                else if (char0 == 'b')
                {
                    /// aab
                    if (found_aab) found_repeated = true; else found_aab = true;
                }
            }
            else if (char1 == 'b')
            {
                if (char0 == 'a')
                {
                    /// aba
                    if (found_aba) found_repeated = true; else found_aba = true;
                }
                else if (char0 == 'b')
                {
                    /// abb
                    if (found_abb) found_repeated = true; else found_abb = true;
                }
            }
        }
        else if (char2 == 'b')
        {
            if (char1 == 'a')
            {
                if (char0 == 'a')
                {
                    /// baa
                    if (found_baa) found_repeated = true; else found_baa = true;
                }
                else if (char0 == 'b')
                {
                    /// bab
                    if (found_bab) found_repeated = true; else found_bab = true;
                }
            }
            else if (char1 == 'b')
            {
                if (char0 == 'a')
                {
                    /// bba
                    if (found_bba) found_repeated = true; else found_bba = true;    
                }
                else if (char0 == 'b')
                {
                    /// bbb
                    if (found_bbb) found_repeated = true; else found_bbb = true;
                }
            }
        }

        ++count;
    }

    cout << char2 << char1 << char0 << " " << count-3 << endl;
}