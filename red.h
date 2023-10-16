#ifndef RED_H
#define RED_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <random>
#include "router.h"

class red
/*Clase que modela un grafo no dirigido unipartito y con pesos.
 *
 * Atributos:
 *      std::map<std::string, router> -> matriz de adyacencia (representacion del grafo).
 *      std::map<std::string, router> ::iterator -> iterador inteligente sobre std::map (matriz de adyacencia).
 *      int routers -> cantidad de nodos en el grafo.
*/
{
private:
    std::map<std::string, router> matriz_adyacencia;
    std::map<std::string, router> ::iterator iterador_red;
    int routers = 0;

    void inicializar_red(std::vector<std::string> &nombres);
/*Funcion que recibe la referencia a un std::vector<std::string>
*y crea una matriz de adyacencia sin conexiones con los nodos presentes en el vector.
*
*@parametros: std::vector<std::string> &.
*@return: void.
*
*Funcion empleada en redrandom().
*/

    void inicializar_red(std::set<std::string> &nombres);
/*Funcion que recibe la referencia a un std::set<std::string>
*y crea una matriz de adyacencia sin conexiones con los nodos presentes en el set.
*
*@parametros: std::vector<std::string> &.
*@return: void.
*
*Funcion empleada en cargarRed().
*/

    void conexion_definida(std::vector<std::string> &info);
/*Funcion que recibe la referencia a un std::vector con el contenido de un archivo con formato
y establece los enlaces entre los distintos nodos indicados en el archivo.
*
*@parametros: std::vector<std::string> &.
*@return: void.
*/

    bool conexion_aleatoria(double *probability);
/*Funcion que recibe un double y segun un evento aleatorio retorna
*un true o false.
*
*@parametros: &double.
*@return: bool.
*/

    std::vector<std::string> nombreAleatorio(int n);
/*Funcion que recibe un entero n y retorna un vector con n strings diferentes.
*
*@parametros: int.
*@return: std::vector<std::string>.
*/

    void cant_nodos(std::string &col1, std::string &col2, std::set<std::string> &nodos);
/*Funcion que recibe dos ubicaciones de memoria a string, una ubicacion de memoria de un set y
*llena el std::set referenciado con los nombres de los nodos.
*
*@parametros: std::string &, std::string &, std::set &.
*@return: void.
*/

    int peso_random();
/*Funcion que genera un entero aleatorio entre 1 y 100.
*
*@parametros: void.
*@return: int.
*/

    void crear_link(std::string &n1, std::string &n2, int peso);
/*Funcion que recibe la ubicacion de memoria de dos string, un entero y
*crea un enlace entre los dos nodos (string n1 &, string n2 &) y les asigna un peso
*int peso.
*
*@parametros: std::string &, std::string& , int.
*@return: void.
*/
    std::string getposi2(int position);
    int getposition(std::string name);
    void printrute(std::string rawrute);
    void printweight(int weight,std::string inicio, std::string final);
    void matrixDijkstra(int cantrouters);
    std::map<std::string, int> dijkstra(int V,int **graph, int src,int final);
    void print_matrix(int n, int **matrix);

    int minDistance(int V, int dist[], bool sptSet[]);
    void delete_P2(int **matrix, int n);
public:
    red();

    void newRouter(std::string key, router name);
/*Funcion que recibe un string y un router y
*los almacena en un std::map.
*
*@parametros: std::string, router.
*@return: void.
*/

    void rmRouter(std::string key);
/*Funcion que recibe un string (nombre del nodo) y elimina el par
* clave-valor del std::map (matriz de adyacencia).
*
*@parametros: std::string.
*@return: void.
*/
    void mod_link(std::string *n1, std::string *n2, int weight);
/*Funcion que recibe dos string * (nombres de los nodos), un int y modifica en la tabla
*de enrutamiento el valor de [*n1], [*n2] por int (-1 equivale a desconectados).
*
*@parametros: std::string *, std::string *, int.
*@return: void.
*/

    void get_names(std::vector<std::string> *nombres);
/*Funcion que recibe un std::vector<std::string> *
*e ingresa los nombres de los nodos en la matriz de adyacencia
*en el vector.
*
*@parametros: std::vector<std::string> *.
*@return: void.
*/

    void set_name(std::string *old_name, std::string *new_name);
/*Funcion que recibe dos string * (nombres de los nodos) y sustituye en la tabla
*de enrutamiento la clave *old_name por *new_name conservando el contenido y la asociatividad.
*
*@parametros: std::string *, std::string *.
*@return: void.
*/

    void cargarRed(std::string nombre, std::string ruta);
/*Funcion que recibe dos std::string (nombre del archivo y ruta) y
*carga el grafo presente en el archivo.
*
*@parametros: std::string, std::string.
*@return: void.
*/

    void redrandom(int routers, double *probability);
/*Funcion que genera un grafo aleatorio dado una probabilidad y una
*cantidad de nodos determinada.
*
*@parametros: int, double.
*@return: void.
*/

    void printRed();
/*Funcion que muestra por consloa la
*informacion de std::map (matriz de adyacencia).
*
*@parametros: void.
*@return: void.
*/

    void ruta_optima();
};

#endif // RED_H
