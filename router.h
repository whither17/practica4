#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <map>
using namespace std;




class router                 //la tabla de enrutamiento hace referencia a la fila n de la matriz de adyacencia que corresponde al enrutador n
{
private:
    map<char,int> adress_table;

public:
    router();
    ~router();
};

#endif // ROUTER_H
