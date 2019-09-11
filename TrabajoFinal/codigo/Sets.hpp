//
//  Sets.hpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#ifndef Sets_hpp
#define Sets_hpp

#include <vector>
#include <algorithm> // Transform
#include <cassert>  // assert

#include "Particiones.hpp"

class Set
{
private:
    vector<Particion> conjunto; // Conjunto de vectores que forma el set
    int tam;                    // Numero de Particiones que forma el set
    Particion suma;             // Partición que contiene la suma de todo el set
    
public:
    
    Set(); // Constructor de la clase
    
    /*
        Getters y Setters de las variables privadas
    */
    
    inline vector<Particion> getConjunto() { return this->conjunto;} // Devuelve el vector de Particiones del Set
    inline void setConjunto(const vector<Particion> particion_tmp){ this->conjunto = particion_tmp;}  // Asigna un conjunto
    inline void addConjunto(const Particion particion_tmp){ this->conjunto.push_back(particion_tmp);}  // Añade una Particion al vector

    inline Particion getParticion(const int posicion){ return this->conjunto[posicion];} // Getter de un elemento del Conjunto del Set
    
    inline int getTam(){ return this->tam;} // Devuelve el tamaño del conjunto
    inline void setTam(const int tam_tmp){ this->tam = tam_tmp;}  // Asigna el tamaño del Set
    
    inline Particion getSuma(){ return this->suma;} // Devuelve la suma del Set
    inline void setSuma(const Particion suma_tmp){ this->suma = suma_tmp;}    // Asigna la suma del Set

    /*
        Funciones del Set.
    */
    
    void introducirParticion(const Particion particion_tmp); // Método que introduce una nueva partición en el Set
    void eleminarParticion(const int posicion); // Método que elimina una partición del Set
    Particion calcularSuma(); // Función que calcula la suma de todo el conjunto de Particiones
};

// Estructura del problema con ambos sets
struct Sets {
    Set s1;
    Set s2;
    int best_fitness;
};

#endif /* Sets_hpp */
