/*  reverseSubstring
    21.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<string>
using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j)
{
    // base
    if (i >= j)
    {}
    else
    {
        // magic
        char c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverseSubstring(s, i+1, j-1);
    }
}

int main()
{
    string s = "abcdefgh";
    reverseSubstring(s, 1, 6);
    cout << s << endl;
}