/*  Simplificació d'un vector d'estudiants agrupats 
    10.04.2024

    ! Solucion sin usar vectores (statement pide el uso de vectores)

    https://github.com/fyodormeteor
*/

#include "Estudiant.hh"

using namespace std;

int main()
{
    int n;
    cin >> n;

    int last_dni;
    double last_nota;

    cin >> last_dni >> last_nota;

    if (last_nota > 10 or last_nota < 0)
    {
        last_nota = -1;
    }

    for (int i = 1; i < n; ++i)
    {
        int current_dni;
        double current_nota;

        cin >> current_dni >> current_nota;

        if (current_dni == last_dni)
        {
            if (current_nota > 10 or current_nota < 0)
            {

            }
            else if (current_nota > last_nota)
            {
                last_nota = current_nota;
            }
        }
        else
        {
            cout << last_dni << ' ';
            if (last_nota == -1)
            {
                cout << "NP";
            }
            else
            {
                cout << last_nota;
            }
            cout << endl;

            last_dni = current_dni;
            
            if (current_nota > 10 or current_nota < 0)
            {
                last_nota = -1;
            }
            else
            {
                last_nota = current_nota;
            }
        }
    }

    cout << last_dni << ' ';
    if (last_nota == -1)
    {
        cout << "NP";
    }
    else
    {
        cout << last_nota;
    }
    cout << endl;
}