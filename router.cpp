#include <iostream>
#include <map>
#include "router.h"
using namespace std;


router::router()
{

}

void router::newlink(char name, int weight)
{
    links++;
    adress_table.insert(pair<char,int>(name, weight));

}

int router::getlink(char name)
{
    return adress_table[name];
}

void router::modlink(char name, int weigth)
{
    adress_table[name] = weigth;
}


void router::removelink(char name)
{
    links--;
    adress_table.erase(name);
}

void router::clearlinks()
{
    adress_table.clear();
    links = 0;
}

void router::printWt(char name)
{
    cout << adress_table[name];
}

void router::printAdress_table()
{
    for(iterador = adress_table.begin(); iterador != adress_table.end(); iterador++ ) {
        cout << iterador -> second << " ";
    }
    cout << endl;
}

char router::nombreRouter()
{
    char nombre;
    for(iterador = adress_table.begin(); iterador != adress_table.end(); iterador++ ) {
        if(iterador -> second == 0) {
            nombre = iterador -> first;
            break;
        }
    }
    return nombre;
}

router::~router()
{

}
