/*  Busqueda lineal en un vector (no main)
    14.02.2024

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <vector>
using namespace std;

/* Buscar  */    
int busqueda_lin(const vector<int>& v, int x)
/* Pre: cierto */
/* Post: si el resultado es v.size(), x no esta en v;
         en caso contrario, indica la posicion de la primera aparicion de x en v */
{
  int tam = v.size();
  int i = 0;
  bool b = false;
  while (i<tam and not b) {
    if (v[i]==x) b=true; 
    else ++i;
  }
  return i;
}