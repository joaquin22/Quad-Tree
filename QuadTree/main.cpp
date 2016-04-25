#include <iostream>
#include <CImg.h>
#include <fstream>
#include "QuadTree.h"

using namespace cimg_library;
using namespace std;

int main()
{
        CImg<float> cimage("test.bmp");
        QuadTree tree;
        cimage = cimage.resize(4,4);
        CImg<float> bin(tree.Binarize(cimage));
        bin.display();
        pair<int,int> p1(0,0);
        pair<int,int> p2 (bin.width()-1,bin.height()-1);
        tree.insertar(bin,p1 , p2);
        tree.Print();
        tree.serilizar();
    return 0;
}
