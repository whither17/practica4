#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <random>
#include "router.h"
#include "red.h"
using namespace std;


red::red()
{

}

void red::newRouter(string name, router _router)
{
    int weight;
    routers++;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        weight = _router.getlink(iterador_red -> first);
        iterador_red -> second.newlink(name, weight);
    }
    matriz_adyacencia.insert(pair<string,router>(name, _router));
}

void red::rmRouter(string key)
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
    int routers_n;


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

int peso_random() {

    int peso;
    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(1, 100);

    peso = distribucion(generador);

    return peso;
}

vector<string> nombreAleatorio(int n){
    int j;
    string nombre = "";
    vector<string> nombres;
    nombre.resize(n);

    for (int i = 1; i <= n; i++) {
        j = i;
        while (j > 0) {
            char letra = 'A' + (j - 1) % 26;
            nombre = letra + nombre;
            j = (j - 1) / 26;
        }

        nombres.push_back(nombre);
        nombre = "";
    }

    return nombres;
}



void red::redrandom(int routers, double probability)
{
    router r1;
    vector<string> nombres = nombreAleatorio(routers);

    for(int i = 0; i < routers; i++) {



        for(int j = 0; j < routers; j++) {
            r1.newlink(nombres[j], peso_random());
        }

        matriz_adyacencia.insert(pair<string,router>(nombres[i], r1));

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
