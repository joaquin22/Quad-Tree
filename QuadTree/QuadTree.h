#ifndef QUADTREE_H
#define QUADTREE_H
#include <fstream>
#include <iostream>
#include "Nodo.h"
#include <CImg.h>
using namespace cimg_library;
using namespace std;
class QuadTree
{
public:
    vector<Nodo> nodosLista;
    void insertar(CImg<float> &imagen, pair<int,int> inicio, pair<int,int>fin);
    bool validar(CImg<float> &imagen, pair<int,int> inicio, pair<int,int>fin, int &color);
    CImg <float> Binarize (CImg<float> &imagen);
    void Print();
    void serilizar();
    QuadTree();
};

#endif // QUADTREE_H
