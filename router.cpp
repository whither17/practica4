#include <iostream>
#include <map>
#include "router.h"
using namespace std;

router::router()
{

}

router::newlink(char name, int weight)
{
    adress_table.insert(pair<char,int>(name, weight));

}

router::removelink(char name)
{

}

router::~router()
{

}
