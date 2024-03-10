/*  Happiness and Sadness (1)
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    char ch0 = ' ', ch1 = ' ', ch2 = ' ';
    int happy = 0;
    int unhappy = 0;

    while(cin >> ch0)
    {
        if(ch2 == ':' and ch1 == '-')
        {
            if (ch0 == ')')         happy++;
            else if (ch0 == '(')    unhappy++;
        }
        else if (ch1 == '-' and ch0 == ':')
        {
            if (ch2 == ')')         unhappy++;
            else if (ch2 == '(')    happy++;
        }

        ch2 = ch1;
        ch1 = ch0;
    }

    cout << happy << ' ' << unhappy << endl;
}