#ifndef RED_H
#define RED_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <random>
#include "router.h"

class red
{
private:
    std::map<std::string, router> matriz_adyacencia;
    std::map<std::string, router> ::iterator iterador_red;
    int routers = 0;

    void inicializar_red(std::vector<std::string> &nombres);
    void inicializar_red(std::set<std::string> &nombres, std::set<std::string> ::iterator it);
    void conexion_definida(std::vector<std::string> &info);
public:
    red();
    void newRouter(std::string key, router name);
    void rmRouter(std::string key);
    void crear_link(std::string &n1, std::string &n2, int peso);
    void cargarRed(std::string nombre, std::string ruta);
    void redrandom(int routers, double probability);
    void printRed();
};

#endif // RED_H
