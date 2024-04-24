#include "Cubeta.hh"

Cubeta::Cubeta()
{

}

Cubeta::Cubeta(const Cubeta& c)
{
    ropacolor = c.ropacolor;
    ropablanca = c.ropablanca;
}

void Cubeta::anadir_prenda(const Prenda& p)
{
    stack<Prenda>* ptr;
    if (p.consul_color()) ptr = &ropacolor;
    else ptr = &ropablanca;

    ptr->push(p);
}

void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l)
{
    int peso = l.consultar_peso();
    int peso_max = l.consultar_peso_maximo();
    int peso_a_anadir = peso_max - peso;
    
    while(!p.empty() and p.top().consul_peso() <= peso_a_anadir)
    {
        Prenda prenda = p.top();
        p.pop();
        l.anadir_prenda(prenda);
        peso_a_anadir -= prenda.consul_peso();
    }
}

void Cubeta::completar_lavadora(Lavadora& lav)
{
    stack<Prenda>* stack_ptr;
    if (lav.consultar_color()) stack_ptr = &ropacolor;
    else stack_ptr = &ropablanca;
    
    completar_lavadora_pila_it(*stack_ptr, lav);
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p)
{
    auto paux = p;
    while (!paux.empty())
    {
        paux.top().escribir();
        paux.pop();
    }
}

void Cubeta::escribir() const
{
    cout << "Ropa de color de la cubeta: " << endl;
    escribir_pila_prenda(ropacolor);
    cout << "Ropa blanca de la cubeta: " << endl;
    escribir_pila_prenda(ropablanca);
    cout << endl;
}