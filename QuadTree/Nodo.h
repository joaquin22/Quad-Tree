#ifndef NODO_H
#define NODO_H
#include <algorithm>

using namespace std;
class Nodo
{
public:
    int Get_color();
    pair<int,int> Get_inicio();
    pair<int,int> Get_fin();
    Nodo();
    Nodo(pair<int,int> inicio, pair<int,int> fin, int color);
private:
    int color;
    pair<int,int> inicio;
    pair<int,int> fin;
};

#endif // NODO_H
