#include <iostream>
#include "funciones.h"
#include "router.h"
#include "red.h"
using namespace std;

int main()
{
    red h;
    h.redrandom(8, 7.1);
    h.printRed();
    return 0;
}
