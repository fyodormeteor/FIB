/*  Gestión de una lavadora
    24.04.2024

    Usar Makefile para crear y entregar program.tar
    "make"

    https://github.com/fyodormeteor
*/

/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
    Lavadora lav = Lavadora();
    Cubeta cub = Cubeta();
    int option;
    cin >> option;

    while (option != -8)
    {
        if (option == -1)
        {
            int pmax;
            cin >> pmax;
            bool color = readbool();
            lav.inicializar(pmax, color);
        }
        else if (option == -2)
        {
            int peso;
            cin >> peso;
            bool color = readbool();
            Prenda pren = Prenda(peso, color);
            lav.anadir_prenda(pren);
        }
        else if (option == -3)
        {
            int peso;
            cin >> peso;
            bool color = readbool();
            Prenda pren = Prenda(peso, color);
            cub.anadir_prenda(pren);
        }
        else if (option == -4)
        {
            cub.completar_lavadora(lav);
        }
        else if (option == -5)
        {
            lav.lavado();
        }
        else if (option == -6)
        {
            cout << "   Cubeta: " << endl;
            cub.escribir();
        }
        else if (option == -7)
        {
            cout << "   Lavadora: " << endl;
            lav.escribir();
        }
        
        cin >> option;
    }
}
