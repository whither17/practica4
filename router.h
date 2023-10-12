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
    router(map<string, int> adres_table, string name);
    void newlink(string name, int weight);
    int getlink(string name);
    int getlinks();
    void setlinks(int links);
    void setlinks_in(int l);
    void modlink(string name, int weigth);
    void removelink(string name);
    void clearlinks();
    void printWt(string key);
    void printAdress_table();
    string nombreRouter();

    ~router();

};

#endif // ROUTER_H
