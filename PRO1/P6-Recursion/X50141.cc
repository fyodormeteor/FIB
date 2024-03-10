/*  Function to fatten numbers
    16.11.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int pow10(int n)
{
    int i = 1;
    while (n > 9)
    {
        n/=10;
        i*=10;
    }
    return i;
}

int fatten(int x)
{
    if (x < 10) return x;
    else
    {
        int p10 = pow10(x);

        int digit2 = x/(p10/10);
        int digit1 = digit2 / 10;
        digit2 = digit2%10;

        int x_rec;
        if (digit1 > digit2)
        {
            x_rec = x%(p10/10) + digit1*(p10/10);
        }
        else x_rec = x%p10;

        return digit1*p10 + fatten(x_rec);
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << fatten(n) << endl;
    }
}