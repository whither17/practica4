#include "red.h"
#include "database.h"



red::red()
{

}

void red::newRouter(std::string name, router _router)
{
    int weight;
    routers++;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        weight = _router.getlink(iterador_red -> first);
        iterador_red -> second.newlink(name, weight);
    }
    matriz_adyacencia.insert(std::pair<std::string,router>(name, _router));
}

void red::rmRouter(std::string name)
{
    routers--;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        iterador_red -> second.removelink(name);
    }
    matriz_adyacencia.erase(name);

}

void red::cargarRed(std::string name, std::string ruta)
{

    std::vector<std::string> info;
    std::set<std::string> nodos;
    std::set<std::string> ::iterator it_set;
    std::string n1;
    database datos_grafo(name,ruta);

    datos_grafo.set_database_separator(' ');
    info.push_back(datos_grafo.get_database_columns()[0]);
    info.push_back(datos_grafo.get_database_columns()[1]);
    info.push_back(datos_grafo.get_database_columns()[2]);
    cant_nodos(info[0], info[1], nodos);

    inicializar_red(nodos);
    for(it_set = nodos.begin(); it_set != nodos.end(); it_set++) {
        n1 = *it_set;
        crear_link(n1,n1, 0);
    }
    conexion_definida(info);

}

void red::redrandom(int routers, double probability)
{
    std::string n1, n2;
    int peso = 0;
    std::vector<std::string> nombres = nombreAleatorio(routers);

    inicializar_red(nombres);

    for(int i = 0; i < routers; i++) {
        n1 = nombres[i];
        for(int j = i; j < routers; j++) {
            n2 = nombres[j];

            if(n1 != n2) {
                if(conexion_aleatoria(&probability)) {
                    peso = peso_random();
                    crear_link(n1, n2, peso);
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
            crear_link(n1, n2, peso);
            peso = 0;
        }
    }
}

void red::printRed()
{

    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        std::cout << iterador_red -> first << " : ";
        iterador_red -> second.printAdress_table();
        std::cout << std::endl;
    }
}

// ***Metodos privados***

void red::conexion_definida(std::vector<std::string> &info) {

    std::vector<std::string> col1, col2, weight;
    int pos = 1;

    for(unsigned int i=0;i<info[0].length() && pos>=0;i=pos+1){
        pos = info[0].find('\n',i);
        col1.push_back(info[0].substr(i,pos-i));
    }
    for(unsigned int i=0;i<info[1].length() && pos>=0;i=pos+1){
        pos = info[1].find('\n',i);
        col2.push_back(info[1].substr(i,pos-i));
    }
    for(unsigned int i=0;i<info[2].length() && pos>=0;i=pos+1){
        pos = info[2].find('\n',i);
        weight.push_back(info[2].substr(i,pos-i));
    }

    for(unsigned int i = 0; i < col1.size(); i++) {
        crear_link(col1[i], col2[i], std::stoi(weight[i]));
    }

}

int red::peso_random()
{

    int peso;
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<int> distribucion(1, 100);

    peso = distribucion(generador);

    return peso;
}

void red::crear_link(std::string &n1, std::string &n2, int peso) {

    matriz_adyacencia[n1].modlink(n2, peso);
    matriz_adyacencia[n1].setlinks_in(1);
    matriz_adyacencia[n2].modlink(n1, peso);
    matriz_adyacencia[n2].setlinks_in(1);
}

void red::cant_nodos(std::string &col1, std::string &col2, std::set<std::string> &nodos) {

    int pos = 1;

    for(unsigned int i=0;i<col1.length() && pos>=0;i=pos+1){
        pos = col1.find('\n',i);
        nodos.insert(col1.substr(i,pos-i));
    }

    for(unsigned int i=0;i<col2.length() && pos>=0;i=pos+1){
        pos = col2.find('\n',i);
        nodos.insert(col2.substr(i,pos-i));
    }
}

std::vector<std::string> red::nombreAleatorio(int n)
{
    int j;
    std::string nombre = "";
    std::vector<std::string> nombres;
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

bool red::conexion_aleatoria(double *probability) {

    bool estado = false;


    std::random_device rd;
    std::mt19937 generador(rd());

    std::bernoulli_distribution distribucion(*probability);
    estado = distribucion(generador);
    return estado;

}

void red::inicializar_red(std::vector<std::string> &nombres) {

    router r1;
    for(unsigned int i = 0; i < nombres.size(); i++) {
        for(unsigned int j = 0; j < nombres.size(); j++) {
            r1.newlink(nombres[j], -1);
        }
        r1.setlinks(0);
        matriz_adyacencia.insert(std::pair<std::string,router>(nombres[i], r1));
        r1.clearlinks();
    }
}

void red::inicializar_red(std::set<std::string> &nombres) {

    router r1;
    std::set<std::string> ::iterator it, it2;
    for(it = nombres.begin(); it != nombres.end(); it++) {
        for(it2 = nombres.begin(); it2 != nombres.end(); it2++) {
            r1.newlink(*it2, -1);
        }
        r1.setlinks(0);
        matriz_adyacencia.insert(std::pair<std::string,router>(*it, r1));
        r1.clearlinks();
    }
}
