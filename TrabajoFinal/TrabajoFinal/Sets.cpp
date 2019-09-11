//
//  Sets.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#include "Sets.hpp"

Set::Set()
{
    // Inicalizamos las variables
    this->tam = 0;
}

Particion Set::calcularSuma()
{
    // Recogemos el Conjunto
    vector<Particion> conjunto_tmp = getConjunto();
    
    // Creamos un vector auxiliar inicializado a 0
    vector<int> vector_suma(conjunto_tmp[0].getTam(), 0);
    
    // Realizamos la suma del conjunto de Particiones
    for (int i = 0; i < conjunto_tmp.size(); i++) {
        transform(vector_suma.begin(), vector_suma.end(), conjunto_tmp[i].getElementos().begin(), vector_suma.begin(), std::plus<int>());
    }
    
    // Creamos una Partición con la nueva suma
    Particion suma(vector_suma);
    
    return suma;
}

void Set::introducirParticion(const Particion particion_tmp)
{
    // Añadimos los datos con la nueva Partición
    addConjunto(particion_tmp);
    
    setTam(getTam() + 1);
    
    setSuma(calcularSuma());
}

void Set::eleminarParticion(const int posicion)
{
    // Comprobamos que la posicion dada esté dentro de la posición
    assert(posicion >= 0 and posicion < getTam());
    
    vector<Particion> tmp = getConjunto();
    
    // Eliminamos esa posición
    tmp.erase(tmp.begin()+posicion);
    
    // Actualizamos el conjunto
    setConjunto(tmp);
    
    // Actualizamos el tamaño del set
    setTam(int(tmp.size()));
    
    // Actualizamos suma
    // Calculamos la diferencia de la suma anterior menos la particion eliminada.
    setSuma(calcularSuma());
}
