/*  Suma de secuencias de enteros
    14.02.2024

    https://github.com/fyodormeteor
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;

    for(int i = 0; i < n; ++i)
    {
        int num;
        int suma = 0;

        while(cin >> num and num != x)
        {
            suma += num;
        }

        cout << "La suma de la secuencia " << i+1 << " es " << suma << endl;

        string s;
        getline(cin,s);
    }
}