#include "QuadTree.h"

void QuadTree::insertar(CImg<float> & imagen, pair<int, int> inicio, pair<int, int> fin)
{

    int color= -1;
    if(validar(imagen, inicio, fin,color)){
        Nodo nod(inicio, fin, color);
        nodosLista.push_back(nod);
    }else{
        pair<int, int> p1((inicio.first + fin.first) / 2, ((inicio.second + fin.second)/2));
        pair<int, int> p2((inicio.first + fin.first) / 2 +1 , (inicio.second));
        pair<int, int> p3( fin.first, ((inicio.second + fin.second)/2));

        pair<int, int> p4( inicio.first, ((inicio.second + fin.second)/2)+1);
        pair<int, int> p5((inicio.first + fin.first) / 2  , (fin.second));
        pair<int, int> p6((inicio.first + fin.first) / 2 +1 , ((inicio.second + fin.second)/2)+1);
        insertar(imagen,inicio, p1);
        insertar(imagen,p2, p3);

        insertar(imagen,p4, p5);
        insertar(imagen,p6, fin);

    }
}

bool QuadTree::validar(CImg<float> &imagen, pair<int, int> inicio, pair<int, int> fin, int &color)
{
    for(int i =inicio.first; i<= fin.first;i++){
        for(int j = inicio.second ; j<= fin.second;j++)
        {
            int newColor = (int)imagen(i, j,0);
            //cout<<newColor<<endl;
            if(color == -1 ){
                color = newColor;
            }else{
             if (color != newColor) return false;
            }
        }
    }
    return true;
}

CImg<float> QuadTree::Binarize(CImg<float> &imagen)
{
    CImg<float> R(imagen);
    for(int i  = 0; i<imagen.width(); i++){
        for(int j  = 0; j<imagen.height(); j++){
            int v = (imagen(i,j,0) + imagen(i,j,1) + imagen(i,j,2) )/3;
            R(i,j,0) = R(i,j,1) = R(i,j,2) = v>80 ? 255:0;
        }

    }
    return R;
}

void QuadTree::Print()
{
    ofstream file;
    file.open("test.txt");
    for(int i = 0; i<nodosLista.size(); i++){
        cout<<nodosLista[i].Get_color()<<" "<<nodosLista[i].Get_inicio().first<<" "<<nodosLista[i].Get_inicio().second<<" "<<nodosLista[i].Get_fin().first<<" "<<nodosLista[i].Get_fin().second<<endl;
        file<<nodosLista[i].Get_color()<<" "<<nodosLista[i].Get_inicio().first<<" "<<nodosLista[i].Get_inicio().second<<" "<<nodosLista[i].Get_fin().first<<" "<<nodosLista[i].Get_fin().second<<endl;
    }
    file.close();
}

void QuadTree::serilizar()
{
    fstream in("test.txt");
    ofstream out("test.dat", ios::out | ios::binary);

    if (in.is_open()) {
        cout << "init binary data..." << endl;

        char data[200];
        int i = 0;
        while (in.getline(data, 200, ';')) {
            int key = atoi(data);
            in.getline(data, 200, '\n');
            out.write((char*)&key, sizeof(int));
            out.write(data, sizeof(char)*200);
            cout << "\r" << ++i;
        }
        in.close();
        cout << endl << "finish binary data..." << endl;
    }
}


QuadTree::QuadTree()
{

}
