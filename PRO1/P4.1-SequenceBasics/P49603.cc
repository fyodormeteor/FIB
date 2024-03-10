/*  Lines in order (2)
    13.10.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    int line = 1;
    int last_line_in_order = 0;
    string word, prev_word;
    bool broken;
    while(cin >> n)
    {
        prev_word = "";
        broken = false;
        for(int i = 0; i < n; ++i)
        {
            cin >> word;
            if (prev_word > word) broken = true;
            prev_word = word;
        }

        if (!broken) last_line_in_order = line;
        ++line;
    }

    if (last_line_in_order > 0)
    {
        cout << "The last line in increasing order is " << last_line_in_order << "." << endl;
    }
    else
    {
        cout << "There is no line in increasing order." << endl;
    }
}