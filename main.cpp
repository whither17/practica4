#include <iostream>
#include "router.h"
#include "red.h"
#include "funciones.h"

void redArchivo(std::string *msj);
void redAleatoria(std::string *msj);

int main()
{
    std::cout << "----------------------------\nPractica 4\nAgudelo Zapata Andres Felipe\nCorrea Morales Robinson\n____________________________\n\n";

    bool prog = true;
    unsigned short opcion, b = 3;
    std::string message = "\n1 - Agregar nuevo enrutador\n2 - Eliminar enrutador\n3 - Modificar enrutador\n4 - Ruta mas optima\n5 - Atras\n";

    while(prog) {

        std::cout << "\n1 - Cargar red desde un archivo\n2 - Crear una red aleatoria\n3 - Salir\n";
        entradaShort(&opcion, &b);

        if(opcion == 1) {
            redArchivo(&message);
        }

        if(opcion == 2) {
            redAleatoria(&message);
        }

        if(opcion == 3) prog = false;
    }

    return 0;
}

void redArchivo(std::string *msj) {
    red Red;
    unsigned short opcion, b = 5;
    std::string ruta_archivo, nombre_archivo;
    nombre_archivo = "grafo.txt";
    ruta_archivo = "H:/ProyectosInfo2/build-practica4-Desktop_Qt_6_5_2_MinGW_64_bit-Debug";
    /*
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;
    std::cout << "Ingrese la ubicacion del archivo: ";
    std::cin >> ruta_archivo;
    */
    Red.cargarRed(nombre_archivo, ruta_archivo );
    std::cout << std::endl;
    Red.printRed();

    while(true) {
        std::cout << *msj;
        entradaShort(&opcion, &b);
        if(opcion == 1) nuevoruter(&Red);
        if(opcion == 2) delrouter(&Red);
        if(opcion == 3) modrouter(&Red);
        if(opcion == 4) rutaOptima(&Red);
        if(opcion == 5) break;
    }

}

void redAleatoria(std::string *msj) {

    std::string mensaje1 = "Ingrese la cantidad de nodos: ";
    std::string mensaje2 = "Ingrese la probabilidad entre 0% y 100%: ";
    red Red;
    int nodos;
    unsigned short opcion, b = 5;
    double prob;

    entradaInt(&nodos, &mensaje1);
    entradaDouble(&prob, &mensaje2);
    Red.redrandom(nodos, &prob);
    Red.printRed();

    std::cout << std::endl;
    while(true) {
        std::cout << *msj;
        entradaShort(&opcion, &b);
        if(opcion == 1) nuevoruter(&Red);
        if(opcion == 2) delrouter(&Red);
        if(opcion == 3) modrouter(&Red);
        if(opcion == 4) rutaOptima(&Red);
        if(opcion == 5) break;
    }
}



