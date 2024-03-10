/*  Control C202D
    21.09.2023

    https://github.com/fyodormeteor
*/

#include<iostream>
using namespace std;

int main()
{
    int a, b;
    int suma_cubs;
    while (cin >> a >> b)
    {
        suma_cubs = 0;
        int i = a;
        while (i <= b)
        {
            suma_cubs += i*i*i;
            ++i;
        }

        cout << "suma dels cubs entre " << a << " i " << b << ": " << suma_cubs << endl;
    }
}