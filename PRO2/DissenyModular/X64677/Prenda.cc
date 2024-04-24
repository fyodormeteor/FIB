/*  Gestión de una lavadora
    24.04.2024

    Usar Makefile para crear y entregar program.tar
    "make"

    https://github.com/fyodormeteor
*/

#include "Prenda.hh"

Prenda::Prenda()
{
    peso = 0;
    color = false;
}

Prenda::Prenda(int pes, bool col)
{
    peso = pes;
    color = col;
}

void Prenda::modificar(int pes, bool col)
{
    peso = pes;
    color = col;
}

int Prenda::consul_peso() const
{
    return peso;
}

bool Prenda::consul_color() const
{
    return color;
}

void Prenda::escribir() const
{
    cout << consul_peso() << ' ';
    if (consul_color()) cout << "true";
    else cout << "false";
    cout << endl;
}