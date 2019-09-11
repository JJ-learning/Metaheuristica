//
//  GetData.hpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#ifndef GetData_hpp
#define GetData_hpp

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>

#include "Particiones.hpp"

using namespace std;

/*
    Genera los ficheros con los datos aleatorios
    Creando M vectores de tamaño N
*/
void generarDatos(int M, int N);

/*
    Leemos los datos de un fichero
*/
vector<Particion> leerDatos(const string nombreFichero);

#endif /* GetData_hpp */
