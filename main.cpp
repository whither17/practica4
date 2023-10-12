#include <iostream>
#include "funciones.h"
#include "router.h"
#include "red.h"
using namespace std;

int main()
{
    red myhappyred;
    myhappyred.redrandom(5, 0.7);
    myhappyred.printRed();
    return 0;
}
