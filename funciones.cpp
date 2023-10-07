#include <iostream>
#include <map>
#include <fstream>
#include "funciones.h"
#include "router.h"
#include "red.h"
using namespace std;


int sizeFile(string name) {

    fstream file;
    file.open(name, ios::in | ios::binary);
    if(file.fail()){
        cout << "\n** No se pudo abrir el archivo **\n";
        exit(EXIT_FAILURE);
    }
    file.seekg(0, ios::end);
    streampos size = file.tellg();
    file.seekg(0, ios::beg);
    file.close();
    return size;
}

string readFile(string name) {

    fstream file;
    string contenido = "";
    char char_;
    int size = sizeFile(name);

    file.open(name, ios::in | ios::binary);
    if(file.fail()) {
        cout << "\n** No se pudo abrir el archivo **\n";
        exit(EXIT_FAILURE);
    }

    else {
        for(int i = 0; i  < size; i++) {
            file.get(char_);
            contenido += char_;
        }
        file.close();
        return contenido;

    }
}
