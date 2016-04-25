#include "Nodo.h"

int Nodo::Get_color()
{
    return color;
}

pair<int, int> Nodo::Get_inicio()
{
    return inicio;
}

pair<int, int> Nodo::Get_fin()
{
    return fin;
}

Nodo::Nodo()
{

}

Nodo::Nodo(pair<int, int> inicio, pair<int, int> fin, int color)
{
 this->inicio = inicio;
    this->fin = fin;
    this->color = color;
}
