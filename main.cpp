#include <iostream>
#include "router.h"
#include "red.h"

int main()
{

    red myhappyred;
    myhappyred.cargarRed("grafo.txt", "H:/ProyectosInfo2/build-practica4-Desktop_Qt_6_5_2_MinGW_64_bit-Debug");
    myhappyred.printRed();

    return 0;
}
