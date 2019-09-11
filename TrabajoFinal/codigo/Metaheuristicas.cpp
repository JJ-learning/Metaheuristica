//
//  Metaheuristicas.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by JoseTorronteras on 09/05/2019.
//  Copyright © 2019 JoseTorronteras. All rights reserved.
//

#include "Metaheuristicas.hpp"

void generarSets(Sets &solucion, const vector<Particion> particiones_fichero)
{
    srand (static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < particiones_fichero.size(); i++) {
        // Asignamos aleatoriamente las Particiones a un conjunto.
        if (rand() % 2 == 0) {
            solucion.s1.introducirParticion(particiones_fichero[i]);
        } else {
            solucion.s2.introducirParticion(particiones_fichero[i]);
        }
    }
}

int busquedaAleatoria(const vector<Particion> particiones_fichero)
{
    // Se definen los sets a usar
    Sets solucion;
    
    // Generamos los sets de manera aleatoria
    generarSets(solucion, particiones_fichero);
    
    // Creamos una partición con la diferencia entre ambos
    Particion resultado(getDiferencia(solucion.s1, solucion.s2));
    
    // Devolvemos el valor del fitness
    return resultado.getFitness();
}

struct Sets busquedaLocal(const struct Sets solucion, const int particion_seleccionada)
{
    // Creamos unos Sets temporales
    Sets solucion_tmp = solucion;
    
    int particion_aux = particion_seleccionada;
    
    // Set Seleccionado
    int set_elegido = 0;
    Set seleccionado;
    
    assert(particion_aux < (solucion_tmp.s1.getTam() + solucion_tmp.s2.getTam()));
    if(particion_aux < solucion_tmp.s1.getTam()) {
        set_elegido = 0;
        seleccionado = solucion_tmp.s1;
    } else {
        set_elegido = 1;
        particion_aux -= solucion_tmp.s1.getTam();
        seleccionado = solucion_tmp.s2;
    }
    
    // Cogemos la particion seleccionada
    Particion tmp = seleccionado.getParticion(particion_aux);
    
    //Eliminamos esa partición
    seleccionado.eleminarParticion(particion_aux);
    
    // Asignamos el set modificado
    if(set_elegido == 0) {
        solucion_tmp.s1 = seleccionado;
        solucion_tmp.s2.introducirParticion(tmp);
        
        // Calculamos el fitness de los sets
        Particion resultado(getDiferencia(solucion_tmp.s1, solucion_tmp.s2));
        solucion_tmp.best_fitness = resultado.getFitness();
    } else {
        solucion_tmp.s2 = seleccionado;
        solucion_tmp.s1.introducirParticion(tmp);
        
        // Calculamos el fitness de los sets
        Particion resultado(getDiferencia(solucion_tmp.s1, solucion_tmp.s2));
        solucion_tmp.best_fitness = resultado.getFitness();
    }
    
    // Devolvemos el valor del fitness
    return solucion_tmp;
    
}

struct Sets busquedaLocalEscaladaSimple(struct Sets &solucion, bool &finalizado)
{
    Sets solucion_aux = solucion;
    
    int fitness_aux = solucion.best_fitness;
    
    Sets current;
    
    for(int i = 0; i < (solucion_aux.s1.getTam()+solucion_aux.s2.getTam()); i++) {
        current = busquedaLocal(solucion_aux, i);
        
        if(current.best_fitness < fitness_aux) {
            finalizado = false;
            return current;
        }
    }
    finalizado = true;
    return solucion_aux;
}

struct Sets busquedaLocalMaximaPendiente(const struct Sets solucion, bool &finalizado)
{
    Sets solucion_aux = solucion;
    
    int fitness_aux = solucion.best_fitness;
    int fitness_inicial = fitness_aux;
    
    Sets best = solucion_aux;
    Sets current;
    
    for(int i = 0; i < (solucion_aux.s1.getTam()+solucion_aux.s2.getTam()); i++) {
        current = busquedaLocal(solucion_aux, i);
        int current_fitness = current.best_fitness;
        
        if(current_fitness < fitness_aux) {
            fitness_aux = current_fitness;
            best = current;
        }
    }
    
    if( fitness_inicial == fitness_aux) {
        finalizado = true;
    } else {
        finalizado = false;
    }
    
    return best;
}

struct Sets greedy(const vector<Particion> particiones_fichero)
{
    Sets solucion;
    Sets solucion1, solucion2;
    Set s1, s2;
    vector<Particion> particiones_tmp(particiones_fichero.size());
    
    for(unsigned int i=0; i < particiones_fichero.size(); i++){
        particiones_tmp[i] = Particion(particiones_fichero[i]);
    }
    
    struct GreaterRow
    {
        int i;
        bool operator()(Particion x, Particion y)
        {
            return x.getElementos()[i] > y.getElementos()[i];
        }
    };
    
    GreaterRow compare;
    
    srand (static_cast<unsigned int>(time(NULL)));
    compare.i = rand()%int(particiones_fichero[0].getTam()); //Seleccionamos la columna por la que ordena

    sort(particiones_tmp.begin(), particiones_tmp.end(), compare);
    
    s1.introducirParticion(particiones_tmp[0]);
    s2.introducirParticion(particiones_tmp[1]);
    
    for(unsigned int i=2; i < particiones_fichero.size(); i++){
        Set aux1 = s1;
        aux1.introducirParticion(particiones_fichero[i]);
        solucion1.s1 = aux1;
        solucion1.s2 = s2;
        
        // Calculamos el fitness de los sets
        Particion resultado_1(getDiferencia(solucion1.s1, solucion1.s2));
        solucion1.best_fitness = resultado_1.getFitness();
        
        Set aux2 = s2;
        aux2.introducirParticion(particiones_tmp[i]);
        solucion2.s1 = s1;
        solucion2.s2 = aux2;
        
        // Calculamos el fitness de los sets
        Particion resultado_2(getDiferencia(solucion2.s1, solucion2.s2));
        solucion2.best_fitness = resultado_2.getFitness();
        
        if(solucion1.best_fitness < solucion2.best_fitness) {
            s1.introducirParticion(particiones_tmp[i]);
        } else {
            s2.introducirParticion(particiones_tmp[i]);
        }
    }
    
    solucion.s1 = s1;
    solucion.s2 = s2;
    
    // Calculamos el fitness de los sets
    Particion resultado_3(getDiferencia(solucion.s1, solucion.s2));
    solucion.best_fitness = resultado_3.getFitness();
    
    return solucion;
}

struct Sets enfriamiento(Sets &neighbour, Sets &solucion_tmp, struct Enfriamiento variables, int &best_fitness)
{
    Sets best;
    
    int i = rand()%(solucion_tmp.s1.getTam()+solucion_tmp.s2.getTam());
    
    neighbour = busquedaLocal(solucion_tmp, i);

    int fitness_variation = neighbour.best_fitness - solucion_tmp.best_fitness;
    
    if(fitness_variation < 0 || variables.p0 <= exp(-fitness_variation/variables.T)){
        solucion_tmp = neighbour;
        solucion_tmp.best_fitness = neighbour.best_fitness;
    }
    if(neighbour.best_fitness < best_fitness){
        best = neighbour;
        best_fitness=neighbour.best_fitness;
    }
    
    return best;
}

vector<int> getDiferencia(Set s1, Set s2)
{
    vector<int> output;
    vector<int> aux_tmp1 = s1.getSuma().getElementos();
    vector<int> aux_tmp2 = s2.getSuma().getElementos();
    
    for (int i = 0; i < aux_tmp1.size(); i++) {
        if(aux_tmp1[i] > aux_tmp2[i]) {
            output.push_back(aux_tmp1[i] - aux_tmp2[i]);
        } else {
            output.push_back(aux_tmp2[i] - aux_tmp1[i]);
        }
    }
    
    return output;
}
