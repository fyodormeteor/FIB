#include "Lavadora.hh"

Lavadora::Lavadora()
{
    ini = false;
}

void Lavadora::inicializar(int pmax, bool col)
{
    pesmax = pmax;
    pes = 0;
    this->col = col;

    ini = true;
}

void Lavadora::anadir_prenda(const Prenda& p)
{
    prendas.push_back(p);
    pes += p.consul_peso();
}

void Lavadora::lavado()
{
    prendas = list<Prenda>();
    ini = false;
}

bool Lavadora::esta_inicializada() const
{
    return ini;
}

bool Lavadora::consultar_color() const
{
    return col;
}

int Lavadora::consultar_peso() const
{
    return pes;
}

int Lavadora::consultar_peso_maximo() const
{
    return pesmax;
}

void Lavadora::escribir() const
{
    if (!ini)
    {
        cout << "Lavadora no inicializada" << endl << endl;
        return;
    }
    
    string type = consultar_color() ? "color" : "blanco";
    cout << "Lavadora de " << type << ", con peso actual " << consultar_peso() << " y peso maximo " << consultar_peso_maximo() << "; sus prendas son" << endl;

    auto it = prendas.begin();
    while (it != prendas.end())
    {
        it->escribir();
        ++it;
    }

    cout << endl;
}