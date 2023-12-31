#include "router.h"

router::router()
{

}

void router::newlink(std::string name, int weight)
{
    links++;
    adress_table.insert(std::pair<std::string,int>(name, weight));

}

int router::getlink(std::string name)
{
    return adress_table[name];
}

int router::getlinks()
{
    return links;
}

void router::setname(std::string name)
{
    adress_table.insert(std::pair<std::string,int>(name, 0));
}

void router::set_name(std::string *old_name, std::string *new_name)
{
    if (adress_table.find(*old_name) != adress_table.end()) {
        adress_table[*new_name] = adress_table[*old_name];
        adress_table.erase(*old_name);
    }
}

void router::setlinks(int links)
{
    this -> links = links;
}

void router::setlinks_in(int l)
{
    links += l;
}

void router::modlink(std::string name, int weigth)
{
    adress_table[name] = weigth;
}


void router::removelink(std::string name)
{
    links--;
    adress_table.erase(name);
}

void router::clearlinks()
{
    adress_table.clear();
    links = 0;
}

void router::printWt(std::string name)
{
    std::cout << adress_table[name];
}

void router::printAdress_table()
{
    for(iterador = adress_table.begin(); iterador != adress_table.end(); iterador++ ) {
        std::cout << iterador -> second << " ";
    }
    std::cout << std::endl;
}

std::string router::nombreRouter()
{
    std::string nombre;
    for(iterador = adress_table.begin(); iterador != adress_table.end(); iterador++ ) {
        if(iterador -> second == 0) {
            nombre = iterador -> first;
            break;
        }
    }
    return nombre;
}

void router::fill_segment(int n, int *matrix){
    iterador = adress_table.begin();
    for(int fil = 0;fil < n; fil++){
        matrix[fil] = iterador -> second;
        iterador++;
    }
}

int* router::dynamic_memory_P2(int n){

    int *matrix;
    matrix = new int[n];
    return matrix;
}

int* router:: getweights(int sizematrix){
    int *matrix = dynamic_memory_P2(sizematrix);
    fill_segment(sizematrix,matrix);
    return matrix;
}


router::~router()
{

}
