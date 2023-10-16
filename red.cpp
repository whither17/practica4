#include "red.h"
#include "database.h"



red::red()
{

}

void red::newRouter(std::string name, router _router)
{
    int weight;
    routers++;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        weight = _router.getlink(iterador_red -> first);
        iterador_red -> second.newlink(name, weight);
    }
    matriz_adyacencia.insert(std::pair<std::string,router>(name, _router));
}

void red::rmRouter(std::string name)
{
    routers--;
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        iterador_red -> second.removelink(name);
    }
    matriz_adyacencia.erase(name);

}

void red::mod_link(std::string *n1, std::string *n2, int weight)
{
    matriz_adyacencia[*n1].modlink(*n2, weight);
    matriz_adyacencia[*n2].modlink(*n1, weight);
}

 void red::get_names(std::vector<std::string> *nombres)
{
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++) {
        nombres->push_back(iterador_red->first);
    }
}

void red::set_name(std::string *old_name, std::string *new_name)
{
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        iterador_red -> second.set_name(old_name, new_name);
    }

    matriz_adyacencia[*new_name] = matriz_adyacencia[*old_name];
    matriz_adyacencia.erase(*old_name);
}

void red::cargarRed(std::string name, std::string ruta)
{

    std::vector<std::string> info;
    std::set<std::string> nodos;
    std::set<std::string> ::iterator it_set;
    std::string n1;
    database datos_grafo(name,ruta);
    try {

        datos_grafo.set_database_separator(' ');
        info.push_back(datos_grafo.get_database_columns()[0]);
    }
    catch (int ex){
        std::cout << "Se ha producido una exepcion. El nombre del archivo o ruta es incorrecto\n";
        exit(-1);
    }
    info.push_back(datos_grafo.get_database_columns()[1]);
    info.push_back(datos_grafo.get_database_columns()[2]);
    cant_nodos(info[0], info[1], nodos);

    inicializar_red(nodos);
    for(it_set = nodos.begin(); it_set != nodos.end(); it_set++) {
        n1 = *it_set;
        crear_link(n1,n1, 0);
    }
    conexion_definida(info);

}

void red::redrandom(int routers, double *probability)
{
    std::string n1, n2;
    int peso = 0;
    std::vector<std::string> nombres = nombreAleatorio(routers);

    inicializar_red(nombres);

    for(int i = 0; i < routers; i++) {
        n1 = nombres[i];
        for(int j = i; j < routers; j++) {
            n2 = nombres[j];

            if(n1 != n2) {
                if(conexion_aleatoria(probability)) {
                    peso = peso_random();
                    crear_link(n1, n2, peso);
                    peso = 0;
                }
            }
            else {
                matriz_adyacencia[n1].modlink(n1, peso);

            }
        }

    }
    for(int k = 0; k < routers; k++) {
        n1 = nombres[k];
        n2 = nombres[routers -1 - k];
        if(matriz_adyacencia[n1].getlinks() == 0) {
            peso = peso_random();
            crear_link(n1, n2, peso);
            peso = 0;
        }
    }
}

void red::printRed()
{

    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        std::cout << iterador_red -> first << " : ";
        iterador_red -> second.printAdress_table();
        std::cout << std::endl;
    }
}

void red::ruta_optima()
{
    std::string a,b;
    std::map<std::string,int> djstr;
    std::map<std::string,int>::iterator dstr;
    int n1,n2;
    int **matrix=new int*[routers];
    iterador_red = matriz_adyacencia.begin();

    for(int fil = 0;fil < routers; fil++){
        matrix[fil] = iterador_red -> second.getweights(routers);
        iterador_red++;
    }

    std::cout<<"Ingrese el nombre del nodo inicial: ";
    std::cin>>a;
    std::cout<<"Ingrese el nombre del nodo Final: ";
    std::cin>>b;
    n1=getposition(a);
    n2=getposition(b);
    djstr=dijkstra(routers,matrix, n1,n2);
    dstr=djstr.begin();
    printweight(dstr->second,a,b);
    printrute(dstr->first);
}


// ***Metodos privados***

void red::conexion_definida(std::vector<std::string> &info) {

    std::vector<std::string> col1, col2, weight;
    int pos = 1;

    for(unsigned int i=0;i<info[0].length() && pos>=0;i=pos+1){
        pos = info[0].find('\n',i);
        col1.push_back(info[0].substr(i,pos-i));
    }
    for(unsigned int i=0;i<info[1].length() && pos>=0;i=pos+1){
        pos = info[1].find('\n',i);
        col2.push_back(info[1].substr(i,pos-i));
    }
    for(unsigned int i=0;i<info[2].length() && pos>=0;i=pos+1){
        pos = info[2].find('\n',i);
        weight.push_back(info[2].substr(i,pos-i));
    }

    for(unsigned int i = 0; i < col1.size(); i++) {
        crear_link(col1[i], col2[i], std::stoi(weight[i]));
    }

}

int red::peso_random()
{

    int peso;
    std::random_device rd;
    std::mt19937 generador(rd());
    std::uniform_int_distribution<int> distribucion(1, 100);

    peso = distribucion(generador);

    return peso;
}

void red::crear_link(std::string &n1, std::string &n2, int peso) {

    matriz_adyacencia[n1].modlink(n2, peso);
    matriz_adyacencia[n1].setlinks_in(1);
    matriz_adyacencia[n2].modlink(n1, peso);
    matriz_adyacencia[n2].setlinks_in(1);
}

void red::cant_nodos(std::string &col1, std::string &col2, std::set<std::string> &nodos) {

    int pos = 1;

    for(unsigned int i=0;i<col1.length() && pos>=0;i=pos+1){
        pos = col1.find('\n',i);
        nodos.insert(col1.substr(i,pos-i));
    }

    for(unsigned int i=0;i<col2.length() && pos>=0;i=pos+1){
        pos = col2.find('\n',i);
        nodos.insert(col2.substr(i,pos-i));
    }
}

std::vector<std::string> red::nombreAleatorio(int n)
{
    int j;
    std::string nombre = "";
    std::vector<std::string> nombres;
    nombre.resize(n);

    for (int i = 1; i <= n; i++) {
        j = i;
        while (j > 0) {
            char letra = 'A' + (j - 1) % 26;
            nombre = letra + nombre;
            j = (j - 1) / 26;
        }

        nombres.push_back(nombre);
        nombre = "";
    }

    return nombres;
}

bool red::conexion_aleatoria(double *probability) {

    bool estado = false;


    std::random_device rd;
    std::mt19937 generador(rd());

    std::bernoulli_distribution distribucion(*probability);
    estado = distribucion(generador);
    return estado;

}

void red::inicializar_red(std::vector<std::string> &nombres) {

    router r1;

    for(unsigned int i = 0; i < nombres.size(); i++) {

        for(unsigned int j = 0; j < nombres.size(); j++) {
            r1.newlink(nombres[j], -1);
        }

        r1.setlinks(0);
        matriz_adyacencia.insert(std::pair<std::string,router>(nombres[i], r1));
        r1.clearlinks();
        routers = nombres.size();
    }
}

void red::inicializar_red(std::set<std::string> &nombres) {

    router r1;
    std::set<std::string> ::iterator it, it2;

    for(it = nombres.begin(); it != nombres.end(); it++) {

        for(it2 = nombres.begin(); it2 != nombres.end(); it2++) {
            r1.newlink(*it2, -1);
        }

        r1.setlinks(0);
        matriz_adyacencia.insert(std::pair<std::string,router>(*it, r1));
        r1.clearlinks();
        routers = nombres.size();
    }
}

void red::print_matrix(int n, int **matrix)
{

    for(int fil = 0;fil < n; fil++){
        for(int col = 0;col < n; col++){
            std::cout << matrix[col][fil] << '\t';
        }
        std::cout << std::endl;
    }
}

int red::minDistance(int V,int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index=999;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min&&dist[v]!=-1)
            min = dist[v], min_index = v;

    return min_index;
}
void red::delete_P2(int **matrix, int n){

    for(int i=0; i<n; i++) delete []matrix[i];
    delete []matrix;
}

std::map<std::string, int> red::dijkstra(int V,int **graph, int src,int final)
{
    std::map<std::string,int> out;
    int dist[V];
    std::string ruta[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    ruta[src]=std::to_string(src);

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(V,dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]!=-1
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                ruta[v]= ruta[u]+","+std::to_string(v);}
    }

    out[ruta[final]]=dist[final];
    delete_P2(graph,V);
    return out;
}

void red::printweight(int weight,std::string inicio, std::string final){

    std::cout<<"El peso minimo desde el nodo "<<inicio<<" hasta el "<<final<<" es: "<<weight<<std::endl;
}

void red::printrute(std::string rawrute){

    std::string rute="",te;
    std::cout<<"La ruta mas optima es: "<<std::endl;
    int n=rawrute.size();

    for(int i=0;i<n;i++){
        if(rawrute[i]!=','){
            rute=rute+rawrute[i];
        }

        else if(rawrute[i]==','){
            te=getposi2(stoi(rute));
            rute="";
            std::cout<<te;
            std::cout<<"->";
        }
    }
    if(rute!=""){

        te=getposi2(stoi(rute));
        std::cout<<te<<std::endl;
    }
}

std::string red::getposi2(int position){

    iterador_red = matriz_adyacencia.begin();
    std::string retu;
    for(int cc = 0;iterador_red != matriz_adyacencia.end(); cc++){
        if(cc==position){
            retu=iterador_red -> first;
            break;
        }
        iterador_red++;
    }
    return retu;
}

int red::getposition(std::string name){

    int cc=0;
    std::string aux="";
    for(iterador_red = matriz_adyacencia.begin(); iterador_red != matriz_adyacencia.end(); iterador_red++ ) {
        for(int i=0;iterador_red -> first[i]!='\0';i++)
            aux=aux+iterador_red -> first[i];
        if(aux==name){
            aux="";
            break;
        }
        else{
            cc++;
            aux="";}
    }
    return cc;
}
