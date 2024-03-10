/*  Generating a grid
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n, m, side;
    while (cin >> n >> m >> side)
    {
        int total_side_length = (1 + m*(side+1));
        char c = '#', s = ' ';

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < total_side_length; ++j)
            {
                cout << c;
            }
            cout << endl;

            for(int j = 0; j < side; ++j)
            {
                for(int k = 0; k < total_side_length; ++k)
                {
                    if (k % (side+1) == 0) cout << c;
                    else cout << s;
                }
                cout << endl;
            }
        }

        for(int i = 0; i < total_side_length; ++i)
        {
            cout << c;
        }
        cout << endl << endl;
    }
}