#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <map>
using namespace std;


class router {

private:
    map<string,int> adress_table;
    map<string,int> ::iterator iterador;
    int links = 0;

public:
    router();
    void newlink(string name, int weight);
    int getlink(string name);
    void modlink(string name, int weigth);
    void removelink(string name);
    void clearlinks();
    void printWt(string key);
    void printAdress_table();
    string nombreRouter();

    ~router();

};

#endif // ROUTER_H
