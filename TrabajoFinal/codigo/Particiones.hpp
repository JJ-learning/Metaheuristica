//
//  Particiones.hpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#ifndef Particiones_hpp
#define Particiones_hpp

#include <iostream>
#include <vector>
#include <numeric>   // std::accumulate
#include <algorithm> // Transform

using namespace std;

class Particion
{
private:
    vector<int> elementos;  // Vector de enteros
    size_t tam;             // Tamaño del vector
    int fitness;            // Valor fitness del vector
    
public:

    Particion(); // Constructores de la clase
    Particion(const vector<int> elementos_tmp); // Constructores de la clase a partir de un vector de enteros
    
    /*
        Getters y Setters de las variables privadas.
    */
    
    inline vector<int> getElementos() const { return this->elementos; } // Devuelve el vector de enteros
    inline size_t getTam() const { return this->tam; }  // Devuelve el tamaño del vector de enteros
    inline int getFitness() const { return this->fitness; } // Devuelve el fitness del vector de enteros
    
};

#endif /* Particiones_hpp */

