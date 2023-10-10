#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <map>
using namespace std;




class router                 //la tabla de enrutamiento hace referencia a la fila n de la matriz de adyacencia que corresponde al enrutador n
{
private:
    map<char,int> adress_table;
    map<char,int> ::iterator iterador;
    int links = 0;

public:
    router();
    void newlink(char name, int weight);
    int getlink(char name);
    void modlink(char name, int weigth);
    void removelink(char name);
    void clearlinks();
    void printWt(char key);
    void printAdress_table();
    char nombreRouter();

    ~router();

};

#endif // ROUTER_H
