/*  Control C201A
    21.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int number_of_digits = 0;
    int current_n = n;
    do {
        number_of_digits++; 
        current_n /= 10;
    } while (current_n);

    int pos = 0;
    int sum = 0;
    current_n = n;
    int dig;
    while (pos < number_of_digits)
    {
        if (pos%2 == 0)
        {
            dig = current_n%10;
            sum += dig;
        }
    
        current_n = current_n/10;
        pos++;
    }

    if (sum%2 == 0) cout << n << " IS COOL" << endl;
    else            cout << n << " IS NOT COOL" << endl;
}