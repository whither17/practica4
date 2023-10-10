#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "router.h"
#include "red.h"
using namespace std;


red::red()
{

}

void red::newRouter(char key, router name)
{
    int weight;
    routers++;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        weight = name.getlink(iterador_red -> first);
        iterador_red -> second.newlink(key, weight);
    }
    matriz_adyacencia.insert(pair<char,router>(key, name));
}

void red::rmRouter(char key)
{
    routers--;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        iterador_red -> second.removelink(key);
    }
    matriz_adyacencia.erase(key);

}

void red::cargarRed(string name)
{
    fstream file;
    streampos size;
    string contenido = "";
    char char_;
    router _router;


    file.open(name, ios::in | ios::binary);
    if(file.fail()){

        cout << "\n** No se pudo abrir el archivo **\n";
        exit(EXIT_FAILURE);

    }

    else {

        file.seekg(0, ios::end);
        size = file.tellg();
        file.seekg(0, ios::beg);

        for(int i = 0; i  < size; i++) {
            file.get(char_);
            contenido += char_;
        }

        file.close();

        cout << contenido;

    }


}

void red::printRed()
{
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        cout << iterador_red -> first << " ";
        iterador_red -> second.printAdress_table();
        cout << endl;
    }

}
