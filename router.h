#ifndef ROUTER_H
#define ROUTER_H
#include <iostream>
#include <map>

class router {
/*Clase que modela el nodo de un grafo no dirigido unipartito y con pesos.
 *
 * Atributos:
 *      std::map<std::string, int> -> tabla de enrutamiento (representación de los enlaces del nodo).
 *      std::map<std::string, int> ::iterator -> iterador inteligente de std::map.
 *      int links -> cantidad de enlaces en el nodo.
*/

private:
    std::map<std::string,int> adress_table;
    std::map<std::string,int> ::iterator iterador;
    int links = 0;

public:
    router(); //constructor;

    void newlink(std::string name, int weight);
/*Funcion que recibe un string y un entero y
*los almacena en un std::map
*
*@parametros: std::string, int.
*@return: void.
*/

    int getlink(std::string name);
/*Funcion que recibe un string y
*busca en un std::map el valor asociado a la clave "std::string name" retornandolo.
*
*@parametros: std::string.
*@return: int.
*/

    int getlinks();
/*Funcion que retorna la cantidad de enlaces del nodo.
*
*@parametros: void.
*@return: int.
*/

    void setlinks(int links);
/*Funcion que recibe un entero y sustituye el valor del
*atributo links por el valor ingresado.
*
*@parametros: int.
*@return: void.
*/

    void setlinks_in(int l);
/*Funcion que recibe un entero y
*suma al atributo links el valor ingresado.
*
*@parametros: int.
*@return: void.
*/

    void modlink(std::string name, int weigth);
/*Funcion que recibe un string y un entero y sustituye
 * el valor de std::map[name] por int weigth (cambia el peso del link).
*
*@parametros: std::string, int.
*@return: void.
*/

    void removelink(std::string name);
/*Funcion que recibe un string y
*elimina el par clave-valor del std::map correspondiente a name.
*
*@parametros: std::string.
*@return: void.
*/

    void clearlinks();
/*Funcion que elimina el contenido de std::map
*
*@parametros: void.
*@return: void.
*/

    void printWt(std::string key);
/*Funcion que recibe un string y
*muestra por consola el valor asociado a key en std::map.
*
*@parametros: std::string.
*@return: void.
*/

    void printAdress_table();
/*Funcion que muestra por pantalla el
*el contenido del std::map
*
*@parametros: void.
*@return: void.
*/

    std::string nombreRouter();
/*Funcion que retorna el nombre del nodo.

@parametros: void.
@return: std::string.
*/

    ~router(); //destructor

};

#endif // ROUTER_H
