#include <iostream>
#include "funciones.h"
#include "router.h"
#include "red.h"
using namespace std;

int main()
{
    red myred;
    router _router;
    int peso;
    char nombre;

        myred.newRouter(_router.nombreRouter(), _router);
        _router.clearlinks();

    myred.printRed();
    myred.rmRouter('B');
    myred.printRed();


        _router.newlink(nombre, peso);


    myred.newRouter(_router.nombreRouter(), _router);
     myred.printRed();



    return 0;
}
