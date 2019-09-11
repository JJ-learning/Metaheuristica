//
//  Funciones.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#include "Funciones.hpp"

void ejecutarBusquedaAleatoria(vector<Particion> particiones_fichero, string nombre_fichero_salida)
{
    // Creamos los medidores de tiempo
    clock_t start_t, end_t;
    double total_t;
    
    // Inicializamos el valor fitness
    int best_fitness = INT_MAX, fitness_busqueda;
    
    // Definimos el fichero de salida
    ofstream out_file(nombre_fichero_salida);
    
    // Inicializamos el reloj
    start_t = clock();
    
    do {
        fitness_busqueda = busquedaAleatoria(particiones_fichero);
        if (fitness_busqueda < best_fitness) {
            // Asignamos el nuevo valor de fitness conseguido
            best_fitness = fitness_busqueda;
        }
        cout << "Fitness de la solución: " << best_fitness << endl;

        // Iteración finalizada
        end_t = clock();
        
        // Calculamos el tiempo de la iteración
        total_t = (double(end_t-start_t)/ double(CLOCKS_PER_SEC));
        
        // Escribimos los datos en el fichero de salida.
        out_file << total_t << " " << best_fitness << endl;
        
    } while(total_t < tiempo_ejecuccion); // Se ejecuta los segundos establecidos.
    
    // Cerramos el fichero de escritura
    out_file.close();
    
    cout << "Mejor Fitness conseguido: " << best_fitness << endl;
}


void ejecutarBusquedaLocalEscaladaSimple(vector<Particion> particiones_fichero, string nombre_fichero_salida)
{
    // Se definen los sets a usar
    Sets solucion;
    
    // Creamos los medidores de tiempo
    clock_t start_t, end_t;
    double total_t;
    
    // Generamos los sets de manera aleatoria
    generarSets(solucion, particiones_fichero);
    
    // Calculamos el fitness de los sets aleatorios
    Particion resultado(getDiferencia(solucion.s1, solucion.s2));
    solucion.best_fitness = resultado.getFitness();
    
    // Definimos el fichero de salida
    ofstream out_file(nombre_fichero_salida);
    
    // Inicializamos el reloj
    start_t = clock();
    
    bool finish = false;
    
    do {
        solucion = busquedaLocalEscaladaSimple(solucion, finish);
        cout << "Fitness de la solución: " << solucion.best_fitness<< endl;

        // Iteración finalizada
        end_t = clock();
        
        // Calculamos el tiempo de la iteración
        total_t = (double(end_t-start_t)/ double(CLOCKS_PER_SEC));
        
        // Escribimos los datos en el fichero de salida.
        out_file << total_t << " " << solucion.best_fitness << endl;
        
    } while(total_t < tiempo_ejecuccion);
    
    // Cerramos el fichero de escritura
    out_file.close();
    
    cout << "Mejor Fitness conseguido: " << solucion.best_fitness << endl;
}

void ejecutarBusquedaLocalMaximaPendiente(vector<Particion> particiones_fichero, string nombre_fichero_salida)
{
    // Se definen los sets a usar
    Sets solucion;
    
    // Creamos los medidores de tiempo
    clock_t start_t, end_t;
    double total_t;
    
    // Generamos los sets de manera aleatoria
    generarSets(solucion, particiones_fichero);
    
    // Calculamos el fitness de los sets aleatorios
    Particion resultado(getDiferencia(solucion.s1, solucion.s2));
    solucion.best_fitness = resultado.getFitness();
    
    // Definimos el fichero de salida
    ofstream out_file(nombre_fichero_salida);
    
    bool finish = false;
    
    // Inicializamos el reloj
    start_t = clock();
    
    do {
        solucion = busquedaLocalMaximaPendiente(solucion, finish);
        cout << "Fitness de la solución: " << solucion.best_fitness<< endl;
        
        // Iteración finalizada
        end_t = clock();
        
        // Calculamos el tiempo de la iteración
        total_t = (double(end_t-start_t)/ double(CLOCKS_PER_SEC));
        
        // Escribimos los datos en el fichero de salida.
        out_file << total_t << " " << solucion.best_fitness << endl;
        
    } while(total_t < tiempo_ejecuccion);
    
    // Cerramos el fichero de esc
    out_file.close();
    
    cout << "Mejor Fitness conseguido: " << solucion.best_fitness << endl;
}

void ejecutarGRASP(vector<Particion> particiones_fichero, string nombre_fichero_salida)
{
    // Se definen los sets a usar
    Sets solucion;
    
    // Creamos los medidores de tiempo
    clock_t start_t, end_t;
    double total_t;
    
    // Definimos el fichero de salida
    ofstream out_file(nombre_fichero_salida);
    
    solucion = greedy(particiones_fichero);
    
    bool finish = false;
    
    // Inicializamos el reloj
    start_t = clock();
    
    do {
        solucion = busquedaLocalMaximaPendiente(solucion, finish);
        cout << "Fitness de la solución: " << solucion.best_fitness<< endl;
        
        // Iteración finalizada
        end_t = clock();
        
        // Calculamos el tiempo de la iteración
        total_t = (double(end_t-start_t)/ double(CLOCKS_PER_SEC));
        
        // Escribimos los datos en el fichero de salida.
        out_file << total_t << " " << solucion.best_fitness << endl;
        
    } while(total_t < tiempo_ejecuccion);
    
    // Cerramos el fichero de esc
    out_file.close();
    
    cout << "Mejor Fitness conseguido: " << solucion.best_fitness << endl;
}

void ejecutarEnfriamientoSimulado(vector<Particion> particiones_fichero, string nombre_fichero_salida)
{
    // Se definen los sets a usar
    Sets solucion, solucion_tmp;
    
    // Creamos los medidores de tiempo
    clock_t start_t, end_t;
    double total_t;
    
    // Generamos los sets de manera aleatoria
    generarSets(solucion_tmp, particiones_fichero);
    
    // Calculamos el fitness de los sets aleatorios
    Particion resultado(getDiferencia(solucion_tmp.s1, solucion_tmp.s2));
    solucion_tmp.best_fitness = resultado.getFitness();
    
    // Definimos el fichero de salida
    ofstream out_file(nombre_fichero_salida);
    
    Enfriamiento variables;
    
    variables.p0 = 0.9;
    variables.alpha = 0.9;
    variables.n = 5;
    
    variables.T0 = calculateT0(particiones_fichero, variables.p0, variables.n);
    variables.T = variables.T0;
    
    solucion = solucion_tmp;
    
    int current_fitness = solucion_tmp.best_fitness;
    int best_fitness = current_fitness;
    
    Sets neighbour;
    
    // Inicializamos el reloj
    start_t = clock();
    
    // ?? int neighbour_fitness;
    variables.TF = (variables.T0 * log(variables.p0))/log(0.0001);
    
    for(int i = 0; variables.T > variables.TF; i++){
        solucion = enfriamiento(neighbour, solucion_tmp, variables, best_fitness);
        
        cool(variables.T, variables.T0, variables.alpha, i+1);
        
        cout<<i<<" "<<variables.T<<" "<<best_fitness<<endl;
        
        // Iteración finalizada
        end_t = clock();
        
        // Calculamos el tiempo de la iteración
        total_t = (double(end_t-start_t)/ double(CLOCKS_PER_SEC));
        
        // Escribimos los datos en el fichero de salida.
        out_file << total_t << " " << best_fitness << endl;
        
        if(total_t > tiempo_ejecuccion) break;
    }

    // Cerramos el fichero de esc
    out_file.close();
    
    cout << "Mejor Fitness conseguido: " << solucion.best_fitness << endl;
}

void cool(double &t,double &t0, const double &alpha, const int &it){
    t=t0/(1+log(it+1)); //boltzmann
    //t*=alpha; //exponencial
    //t=t0-(alpha*it); //lineal
    //t=t0/(1+it); //cauchy
}

double calculateT0(const vector<Particion> &problem,const double &p0, const int &n){
    int total=0;
    
    for(int i=0; i<n; i++){
        Sets current;
        // Generamos los sets de manera aleatoria
        generarSets(current, problem);
        
        // Creamos una partición con la diferencia entre ambos
        Particion resultado(getDiferencia(current.s1, current.s2));
        
        current.best_fitness = resultado.getFitness();
        
        int current_fitness = current.best_fitness;
        
        Sets neighbour = busquedaLocal(current, rand()%(current.s1.getTam()+current.s2.getTam()));
        
        int neighbour_fitness = neighbour.best_fitness;
        
        int fitness_variation = abs(neighbour_fitness-current_fitness);
        
        total-=fitness_variation;
    }
    
    return (total/n)/log(p0);
    }
