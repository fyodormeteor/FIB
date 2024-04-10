/*  Arrodonir un vector d'estudiants (no main) 
    10.04.2024

    https://github.com/fyodormeteor
*/

#include "Estudiant.hh"

#include <vector>

   /* Pre: cert */
   /* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
 a la decima mes propera */
void arrodonir_vector(vector<Estudiant>& v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[i].te_nota())
        {
            double nota = v[i].consultar_nota();

            nota = (int(10. * (nota + 0.05))) / 10.;

            v[i].modificar_nota(nota);
        }
    }
}
