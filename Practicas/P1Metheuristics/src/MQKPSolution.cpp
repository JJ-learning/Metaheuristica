/*
 * MQKPSolution.cpp
 *
 * Fichero que define los métodos de la clase MQKPSolution. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPSolution.h"
#include "MQKPInstance.h"


MQKPSolution::MQKPSolution(MQKPInstance &instance)
{
	this->_numObjs = instance.getNumObjs();
	this->_fitness = 0.0;
	this->_sol.resize(_numObjs);
}

MQKPSolution::~MQKPSolution()
{
	this->_sol.clear();
}

void MQKPSolution::putObjectIn(int object, int knapsack)
{
	this->_sol[object] = knapsack;
}

int MQKPSolution::whereIsObject(int object)
{
	return this->_sol[object];
}


//TODO completar inicializando las variables miembro. Inicialmente, todos los objetos estarán fuera de las mochilas ( = 0)