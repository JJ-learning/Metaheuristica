//
//  Particiones.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#include "Particiones.hpp"

Particion::Particion()
{
    // Inicalizamos las variables
    this->tam = 0;
    this->fitness = 0;
}

Particion::Particion(const vector<int> elementos_tmp)
{
    // Inicalizamos las variables a partir de un vector de enteros.
    this->elementos = elementos_tmp;
    this->tam = elementos_tmp.size();
    this->fitness = *max_element(elementos_tmp.begin(), elementos_tmp.end());
}
