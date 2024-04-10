/*  Mitjanes selectives  
    10.04.2024

    https://github.com/fyodormeteor
*/

#include "Estudiant.hh"

#include <set>

int main()
{
    int m, n, s;
    cin >> m >> n >> s;

    set<int> selected_subjects;
    
    for (int i = 0; i < s; ++i)
    {
        int aux;
        cin >> aux;
        selected_subjects.insert(aux);
    }

    for (int i = 0; i < m; ++i)
    {
        int dni;
        cin >> dni;
        double average_nota = 0;

        for (int j = 0; j < n; ++j)
        {
            double nota;
            cin >> nota;
            
            if (selected_subjects.count(j+1) == 1)
            {
                average_nota += nota/s;
            }
        }

        cout << dni << ' ' << average_nota << endl;
    }
}