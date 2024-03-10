/*  Generating sequences of rombes
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int numspaces, numrombes;
    int spaces_before, spaces_after;
    char c = '*';
    char s = ' ';

    while (cin >> numspaces >> numrombes)
    {
        for(int i = 0; i < numrombes; ++i)
        {
            spaces_before = numspaces+1; // +1 to account for initial for assingment (--spaces_before;)
            spaces_after = -1 -2; // -2 to account for initial for assignment (spaces_after+=2;)

            for(int j = 0; j < (numspaces + 1); ++j)
            {
                --spaces_before;
                spaces_after+=2;
                
                for(int k = 0; k < spaces_before; ++k) cout << s;
                cout << c;
                for(int k = 0; k < spaces_after; ++k) cout << s;
                if (spaces_after != -1) cout << c;
                cout << endl;
            }

            for(int j = 0; j < (numspaces - 1); ++j)
            {
                ++spaces_before;
                spaces_after-=2;
                
                for(int k = 0; k < spaces_before; ++k) cout << s;
                cout << c;
                for(int k = 0; k < spaces_after; ++k) cout << s;
                cout << c << endl;
            }
        }

        for(int i = 0; i < numspaces; ++i) cout << s;
        cout << c << endl << endl;
    }
}