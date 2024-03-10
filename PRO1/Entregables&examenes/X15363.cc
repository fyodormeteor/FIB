/*  Recursive sequence of rombes
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

void draw_line(int& length, int count) // Function to draw lines of spaces and '*'.
{                                      // Uses a reference (int& length) to an unmodified n value to keep the rhombus centered for any n.
    const char c = '*';
    const char s = ' ';

    for(int i = 0; i < (length-count); ++i) cout << s;
    for(int i = 0; i < (count*2 - 1); ++i)  cout << c;
    cout << endl;
}

void draw_rhombus(int& length, int n) // Recursive function. Also stores a reference to the unmodified n value
{                                     // to pass it to the above function.
    if (n == 1) draw_line(length, 1);
    else
    {
        draw_rhombus(length, n-1);
        for(int i = 0; i < n-1; ++i)   draw_line(length, 2+i);
        for(int i = 1; i < n-1; ++i)   draw_line(length, n-i);
        draw_rhombus(length, n-1);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        draw_rhombus(n, n);
        cout << endl;
    }
}