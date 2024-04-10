/*  Nota màxima i mínima d'un vector d'estudiants (no main)
    10.04.2024

    https://github.com/fyodormeteor
*/

#include "Estudiant.hh"

#include <vector>

 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
pair<int,int>  max_min_vest(const vector<Estudiant>& v)
{
    int pos_min = -1;
    double nota_min = Estudiant::nota_maxima();
    int dni_min = -1;

    int pos_max = -1;
    double nota_max = -1;
    int dni_max = -1;
    
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[i].te_nota())
        {
            double nota = v[i].consultar_nota();
            int dni = v[i].consultar_DNI();
            
            if (nota < nota_min or (nota == nota_min and dni < dni_min))
            {
                nota_min = nota;
                dni_min = dni;

                pos_min = i;
            }

            if (nota > nota_max or (nota == nota_max and dni < dni_max))
            {
                nota_max = nota;
                dni_max = dni;

                pos_max = i;
            }
        }
    }

    return pair<int,int>(pos_max, pos_min);
}