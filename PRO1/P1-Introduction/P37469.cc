/*  Time decomposition (1)
    21.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = n%60;
    int m = n/60;
    int h = m/60;
    m -= 60*h;

    cout << h << " " << m << " " << s << endl;
}