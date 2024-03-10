/*  Generating zig-zags
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    const char c = '#';
    const char s = '*';
    
    int height, width;
    while(cin >> height >> width)
    {
        int offset = 0;
        int change = 1;
        for(int i = 0; i < height; ++i)
        {
            int j = 0;
            while(j < offset)
            {
                cout << s;
                ++j;
            }
            while(j < offset+width/2)
            {
                cout << c;
                ++j;
            }
            while(j < width)
            {
                cout << s;
                ++j;
            }

            if (offset == 0)        change = 1;
            if (offset == width/2)  change = -1;

            offset += change;

            cout << endl;
        }

        cout << endl;
    }
}