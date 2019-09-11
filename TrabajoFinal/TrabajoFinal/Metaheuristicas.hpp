//
//  Metaheuristicas.hpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#ifndef Metaheuristicas_hpp
#define Metaheuristicas_hpp

#include <stdio.h>
#include <climits> // INTMAX
#include <math.h> // log - exp

#include "Particiones.hpp"
#include "Sets.hpp"

using namespace std;

struct Enfriamiento {
    double p0;
    double alpha;
    int n;
    double T0;
    double T;
    double TF;
};

/**
 Nombre: generarSets
 Descripción: Genera aleatoriamente los conjuntos a partir de las particiones de un fichero.
 Argumentos:
    - Sets &solucion: Estrucutra con las Instancias de la clase Set.
    - vector<Particion> particiones_fichero: Vector de Instancias de la clase Particion.
 **/
void generarSets(Sets &solucion, const vector<Particion> particiones_fichero);

/**
 Nombre: busquedaAleatoria
 Descripción: Realiza la metaheurística aleatoria, generando dos conjuntos aleatorios, calcula
    la diferencia entre ambos y devuelve la distancia mayor entre ellos.
 Argumentos:
    - vector<Particion> particiones_fichero: Vector de Instancias de la clase Particion.
 Return:
    - resultado.getFitness(): La distancia mayor calculada.
 **/
int busquedaAleatoria(const vector<Particion> particiones_fichero);

/**
 **/
struct Sets busquedaLocal(const struct Sets solucion, const int particion_seleccionada);

/**
 Nombre: busquedaLocal
 Descripción: Realiza la metaheurística de búsqueda local, generando dos conjuntos aleatorios, calcula
 la diferencia entre ambos y devuelve la distancia mayor entre ellos.
 Argumentos:
 - Set s1:
 - Set s2:
 - vector<Particion> particiones_fichero: Vector de Instancias de la clase Particion.
 Return:
 - resultado.getFitness(): La distancia mayor calculada.
 **/
struct Sets busquedaLocalEscaladaSimple(struct Sets &solucion, bool &finalizado);

/**
 **/
struct Sets busquedaLocalMaximaPendiente(const struct Sets solucion, bool &finalizado);

struct Sets greedy(const vector<Particion> particiones_fichero);

struct Sets enfriamiento(Sets &neighbour, Sets &solucion_tmp, struct Enfriamiento variables, int &best_fitness);
/**
 Nombre: getDiferencia
 Descripción: Calcula la diferencia entre dos conjuntos.
 Argumentos:
     - Set s1: Instancia de la clase Set.
     - Set s2: Instancia de la clase Set.
 Return:
    - vector<int> output: Vector resultante tras calcular la diferencia.
 **/
vector<int> getDiferencia(Set s1, Set s2);

#endif /* Metaheuristicas_hpp */
