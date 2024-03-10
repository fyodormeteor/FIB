/*  Number of peaks in input numbers
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int peaks = 0;
        int n0 = 9, n1 = 9, n2 = 9;

        while(n > 0)
        {
            n0 = n1;
            n1 = n2;
            n2 = n % 10;
            n /= 10;

            if (n1 > n2 and n1 > n0) ++peaks;
        }

        cout << peaks << endl;
    }
}