// todo: fix xd

#include "Cjt_estudiants.hh"
#include <algorithm>

/* Pre: el paràmetre implícit no està ple */
/* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
   si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */
void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
   int i = nest-1;
   int dni = est.consultar_DNI();

   if (dni == vest[cerca_dicot(vest, 0, i, dni)].consultar_DNI())
   {
      b = true;
   }
   else
   {
      b = false;
   }

   if (!b)
   {
      bool a = false;
      
      while (i >= 0 and not a) {  
         if ( dni> vest[i].consultar_DNI()) a = true;
         else {
            vest[i+1]=vest[i];
            --i;
         }
      }
      // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
      // si no, i=-1 

      vest[i+1] = est;
      ++nest;

      if (est.te_nota())
      {
         suma_notes += est.consultar_nota();
         nest_amb_nota++;
      }
   }
}

/* Pre: cert */
/* Post: b indica si el paràmetre implícit original tenia un estudiant 
   amb el dni dni; si b, aquest estudiant ha quedat eliminat
   del paràmetre implícit */
void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
   int i = cerca_dicot(vest,0,nest-1,dni);
   
   if (dni == vest[i].consultar_DNI())
   {
      b = true;
   }
   else
   {
      b = false;
   }
   
   if (b)
   {
      auto it = vest.begin();
      it += i;

      if (vest[i].te_nota())
      {
         suma_notes -= vest[i].consultar_nota();
         nest_amb_nota--;
      }

      vest.erase(it);
      nest--;
   }
}