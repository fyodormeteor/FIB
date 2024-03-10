/*  Temperatures
    14.09.2023

    https://github.com/fyodormeteor
*/

#include <iostream>
using namespace std;

int main()
{
    int temp;
    cin >> temp;

    if (temp > 30) cout << "it's hot" << endl;
    else if (temp < 10) cout << "it's cold" << endl;
    else cout << "it's ok" << endl;

    if (temp >= 100) cout << "water would boil" << endl;
    if (temp <= 0) cout << "water would freeze" << endl;
}