//
//  Funciones.hpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <iostream>
#include <fstream> // ofstream
#include <climits> // INTMAX
#include <ctime>
#include <cmath>

#include "Particiones.hpp"
#include "Metaheuristicas.hpp"

using namespace std;

extern int tiempo_ejecuccion;

void ejecutarBusquedaAleatoria(vector<Particion> particiones_fichero, string nombre_fichero_salida);
void ejecutarBusquedaLocalEscaladaSimple(vector<Particion> particiones_fichero, string nombre_fichero_salida);
void ejecutarBusquedaLocalMaximaPendiente(vector<Particion> particiones_fichero, string nombre_fichero_salida);
void ejecutarGRASP(vector<Particion> particiones_fichero, string nombre_fichero_salida);
void ejecutarEnfriamientoSimulado(vector<Particion> particiones_fichero, string nombre_fichero_salida);

double calculateT0(const vector<Particion> &problem,const double &p0, const int &n);
void cool(double &t,double &t0, const double &alpha, const int &it);
#endif /* Funciones_hpp */

