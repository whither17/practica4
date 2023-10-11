#include <iostream>
#include <map>
#include "router.h"
using namespace std;


router::router(map<string, int> adres_table)
{

}

void router::newlink(string name, int weight)
{
    links++;
    adress_table.insert(pair<string,int>(name, weight));

}

int router::getlink(string name)
{
    return adress_table[name];
}

void router::modlink(string name, int weigth)
{
    adress_table[name] = weigth;
}


void router::removelink(string name)
{
    links--;
    adress_table.erase(name);
}

void router::clearlinks()
{
    adress_table.clear();
    links = 0;
}

void router::printWt(string name)
{
    cout << adress_table[name];
}

void router::printAdress_table()
{
    for(iterador = adress_table.begin(); iterador != adress_table.end(); iterador++ ) {
        cout << iterador -> second << "fil ";
    }
    cout << endl;
}

string router::nombreRouter()
{
    string nombre;
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
