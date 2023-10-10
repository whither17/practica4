#ifndef RED_H
#define RED_H
#include <iostream>
#include <map>
#include "router.h"
using namespace std;

class red
{
private:
    map<char, router> matriz_adyacencia;
    map<char, router> ::iterator iterador_red;
    int routers = 0;
public:
    red();
    void newRouter(char key, router name);
    void rmRouter(char key);
    void cargarRed(string nombre);
    void printRed();
};

#endif // RED_H
