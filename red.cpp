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

void red::rmRouter(string name)
{
    routers--;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        iterador_red -> second.removelink(name);
    }
    matriz_adyacencia.erase(name);

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

int peso_random()
{

    int peso;
    random_device rd;
    mt19937 generador(rd());
    uniform_int_distribution<int> distribucion(1, 100);

    peso = distribucion(generador);

    return peso;
}

vector<string> nombreAleatorio(int n)
{
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

bool conexion_aleatoria(double *probability) {

    bool estado = false;


       random_device rd;
       mt19937 generador(rd());

       bernoulli_distribution distribucion(*probability);
       estado = distribucion(generador);
    return estado;

}

void llenar_matriz(map<string, router> &matriz, vector<string> &nombres) {

    router r1;
    for(unsigned int i = 0; i < nombres.size(); i++) {
        for(unsigned int j = 0; j < nombres.size(); j++) {
            r1.newlink(nombres[j], -1);
        }
        r1.setlinks(0);
        matriz.insert(pair<string,router>(nombres[i], r1));
        r1.clearlinks();
    }
}

void crear_link(map<string, router> &matriz, string &n1, string &n2, int peso) {

    matriz[n1].modlink(n2, peso);
    matriz[n1].setlinks_in(1);
    matriz[n2].modlink(n1, peso);
    matriz[n2].setlinks_in(1);
}


void red::redrandom(int routers, double probability)
{
    string n1, n2;
    int peso = 0;
    vector<string> nombres = nombreAleatorio(routers);

    llenar_matriz(matriz_adyacencia, nombres);

    for(int i = 0; i < routers; i++) {
        n1 = nombres[i];
        for(int j = i; j < routers; j++) {
            n2 = nombres[j];

            if(n1 != n2) {
                if(conexion_aleatoria(&probability)) {
                    peso = peso_random();
                    crear_link(matriz_adyacencia, n1, n2, peso);
                    peso = 0;
                }
            }
            else {
                matriz_adyacencia[n1].modlink(n1, peso);

            }
        }

    }
    for(int k = 0; k < routers; k++) {
        n1 = nombres[k];
        n2 = nombres[routers -1 - k];
        if(matriz_adyacencia[n1].getlinks() == 0) {
            peso = peso_random();
            crear_link(matriz_adyacencia, n1, n2, peso);
            peso = 0;
        }
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
