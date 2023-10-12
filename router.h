#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <map>

class router {

private:
    std::map<std::string,int> adress_table;
    std::map<std::string,int> ::iterator iterador;
    int links = 0;

public:
    router();
    router(std::map<std::string, int> adres_table, std::string name);
    void newlink(std::string name, int weight);
    int getlink(std::string name);
    int getlinks();
    void setlinks(int links);
    void setlinks_in(int l);
    void modlink(std::string name, int weigth);
    void removelink(std::string name);
    void clearlinks();
    void printWt(std::string key);
    void printAdress_table();
    std::string nombreRouter();

    ~router();

};

#endif // ROUTER_H
