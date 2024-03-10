/*  Harmonic numbers (1)
    28.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int n;
    cin >> n;

    double result = 0;

    int i = 1;
    while(i<=n)
    {
        result += 1.0/i;
        ++i;
    }

    cout << result << endl;
}