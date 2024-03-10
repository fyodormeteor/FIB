/*  Happiness and Sadness (2)
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    char ch, ch0 = ' ', ch1 = ' ', ch2 = ' ';
    int happy = 0, unhappy = 0;
    
    while(cin >> ch)
    {
        if (!(ch0 == '-' and ch == '-')) // Ignore a '-' if last read character was already a '-'
        {
            ch2 = ch1;
            ch1 = ch0;
            ch0 = ch;

            if (ch2 == ':' and ch1 == '-')
            {
                    if(ch0 == ')')          happy++;
                    else if (ch0 == '(')    unhappy++;
            }
            else if (ch2 == '(' and ch1 == '-' and ch0 == ':') happy++;
            else if (ch2 == ')' and ch1 == '-' and ch0 == ':') unhappy++;
        }   
    }
    
    cout << happy << ' ' << unhappy << endl;
}