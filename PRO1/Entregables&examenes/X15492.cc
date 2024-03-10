/*  Add one to even digits
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int a;
    while(cin >> a)
    {
        int out = 0;
        int pow10 = 1;
        while(a > 0)
        {
            int last = a%10;
            a /= 10;

            if (last%2 == 0) ++last;

            out += last*pow10;
            pow10 *= 10;
        }

        cout << out << endl;
    }
}