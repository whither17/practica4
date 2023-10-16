#include "funciones.h"

void entradaShort(unsigned short *numero, unsigned short *b)
{
    while(true) {
        std::cout << "Ingrese una opcion: ";
        if(std::cin >> *numero) {
            if((*numero < 0) || (*numero > *b)) std::cout << "Opcion no valida\n";
            else break;
        }
        else {
            std::cout << "Entrada no valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void entradaInt(int *numero, std::string *ms)
{

    while(true) {
        std::cout << *ms;
        if(std::cin >> *numero) break;
        else {
            std::cout << "Entrada no valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void entradaDouble(double *numero, std::string *ms)
{
    double n;
    while(true) {
        std::cout << *ms;
        if(std::cin >> n) {
            if((n > 0) && (n <= 100)) break;
            else std::cout << "El numero no esta entre 0 y 100\n";
        }
        else {
            std::cout << "Entrada no valida\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    *numero = n/100;
}

void elegirNodo(std::vector<std::string> *nombres, std::string *n1)
{
    while(true) {

        std::cout << "Ingrese el nombre del router: ";
        std::cin >> *n1;
        auto pos = std::find(nombres->begin(), nombres->end(), *n1);
        if(pos != nombres->end()) {
            break;
        }
        else {
            std::cout << "El router no exixte\n";
        }
    }
}

void modNombre(std::vector<std::string> *nombres, std::string *n1, std::string *n2, red *Red)
{
    while(true) {

        std::cout << "Ingrese el nuevo nombre: " ;
        std::cin >> *n2;
        auto pos = std::find(nombres->begin(), nombres->end(), *n2);
        if(pos == nombres->end()) {
            break;
        }
        else {
            std::cout << "El nombre ya esta en uso\n";
        }
    }

    Red->set_name(n1, n2);
    std::cout << std::endl;
    Red->printRed();
}

void eliminarEnlace(std::vector<std::string> *nombres, std::string *nombre1, std::string *nombre2, red *Red)
{
    elegirNodo(nombres,nombre2);
    Red->mod_link(nombre1, nombre2, -1);
    std::cout << std::endl;
    Red->printRed();
}

void modEnlace(std::vector<std::string> *nombres, std::string *nombre1, std::string *nombre2, red *Red)
{
    int peso;
    std::string ms = "Ingrese nuevo peso: ";
    entradaInt(&peso, &ms);
    elegirNodo(nombres,nombre2);
    Red->mod_link(nombre1, nombre2, peso);
    std::cout << std::endl;
    Red->printRed();
}

void modEnlaces()
{
    std::cout<<"proximamente\n";
}

void nuevoruter(red *Red)
{
    router nodo;
    int peso;
    std::string nombre;
    std::string mensaje = "Ingrese un entero entre 1 y 100: ";
    std::vector<std::string> nombres;
    Red->get_names(&nombres);

    std::cout << std::endl;

    while(true) {

        std::cout << "Ingrese el nombre del nuevo router: ";
        std::cin >> nombre;
        auto pos = std::find(nombres.begin(), nombres.end(), nombre);
        if(pos == nombres.end()) {
            break;
        }
        else {
            std::cout << "El nombre ya esta en uso\n";
        }
    }
    nodo.setname(nombre);

    for(int i = 0; i < nombres.size(); i++) {
        std::cout << "Ingrese el peso del enlace con " << nombres[i] << ":\n";
        entradaInt(&peso, &mensaje);
        nodo.newlink(nombres[i], peso);
    }

    Red->newRouter(nodo.nombreRouter(), nodo);
    std::cout << std::endl;
    Red->printRed();
}

void delrouter(red *Red)
{
    std::string nombre;
    std::vector<std::string> nombres;
    Red->get_names(&nombres);

    std::cout << std::endl;

    while(true) {
        std::cout << "Ingrese el nombre del nodo a eliminar: ";
        std::cin >> nombre;
        auto pos = std::find(nombres.begin(), nombres.end(), nombre);
        if(pos != nombres.end()) {
            break;
        }
        else {
            std::cout << "El nodo no existe\n";
        }
    }

    Red->rmRouter(nombre);
    std::cout << std::endl;
    Red->printRed();
}

void modrouter(red *Red)
{
    unsigned short opcion, b = 5;
    int peso;
    std::string nombre1, nombre2;
    std::vector<std::string> nombres;

    Red->get_names(&nombres);

    elegirNodo(&nombres, &nombre1);

    while(true) {
        std::cout << "\n1 - Modificar nombre del enrutador\n2 - Eliminar un enlace\n3 - Modificar un enlace\n4 - Modificar todos los enlaces\n5 - Atras\n";
        entradaShort(&opcion, &b);

        if(opcion == 1) {
            modNombre(&nombres, &nombre1, &nombre2, Red);
        }

        if(opcion == 2) {
            eliminarEnlace(&nombres, &nombre1, &nombre2, Red);
        }

        if(opcion == 3) {
            modEnlace(&nombres, &nombre1, &nombre2, Red);
        }

        if(opcion == 4) {

        }

        if(opcion == 5) break;
    }
}

void rutaOptima(red *Red)
{
    std::cout << std::endl;
    Red->ruta_optima();
}
