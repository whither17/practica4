#ifndef RED_H
#define RED_H
#include <iostream>
#include <map>
#include "router.h"
using namespace std;

class red
{
private:
    map<string, router> matriz_adyacencia;
    map<string, router> ::iterator iterador_red;
    int routers = 0;
public:
    red();
    void newRouter(string key, router name);
    void rmRouter(string key);
    void cargarRed(string nombre);
    void redrandom(int routers, double probability);
    void printRed();
};

#endif // RED_H
