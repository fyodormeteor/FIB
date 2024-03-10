/*  First odd digits (1,3,5,7,9), next positive even digits (2,4,6,8)
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    int len, x_aux;
    int i, j;
    int current_digit, power_of_ten, odd_digits, even_digits, amount_of_even_digits;

    while(cin >> x)
    {
        len = 0;
        x_aux = x;
        while(x_aux != 0)
        {
            x_aux /= 10;
            ++len;
        } // get length of number

        odd_digits = 0;
        even_digits = 0;
        amount_of_even_digits = 0;
        
        i = len;
        x_aux = x;
        while(i > 0)
        {
            j = 0;
            power_of_ten = 1;
            while(j < i-1)
            {
                power_of_ten*=10;
                ++j;
            } // get power of ten associated with digit position (aka 10 to the power of i)
            
            current_digit = x_aux/power_of_ten;
            x_aux = x%power_of_ten;

            if (current_digit%2 == 1)
            {
                odd_digits*=10;
                odd_digits+=current_digit;
            }
            else if (current_digit != 0)
            {
                even_digits*=10;
                even_digits+=current_digit;
                ++amount_of_even_digits;
            }

            --i;
        }

        j = 0;
        power_of_ten = 1;
        while(j < amount_of_even_digits)
        {
            power_of_ten*=10;
            ++j;
        } // get power of ten associated with the amount of even digits
        y = odd_digits*power_of_ten + even_digits;
        z = y*2;

        cout << y << " " << z << endl;
    }
}
