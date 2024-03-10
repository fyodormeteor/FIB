/*  Positions of a maximum within two sequences
    09.11.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

void infoSequence(int& max, int& lpos)
{
    max = 0;
    lpos = 1;
    int n, pos = 1;
    cin >> n;
    while(n != 0)
    {
        if (n >= max)
        {
            max = n;
            lpos = pos;
        }
        cin >> n;
        pos++;
    }
}

int main()
{
    int max, pos1;
    infoSequence(max, pos1);

    int n, pos = 1, pos2 = -1;
    bool found = false;
    cin >> n;
    while(n != 0 and !found)
    {
        if (n == max)
        {
            pos2 = pos;
            found = true;
        }
        cin >> n;
        pos++;
    }

    cout << max << ' ' << pos1 << ' ';
    if (pos2 > 0) cout << pos2;
    else cout << '-';
    cout << endl;
}
