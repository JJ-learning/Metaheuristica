/*
 * MQKPObjectAssignmentOperation.cpp
 *
 * Fichero que define las funciones de la clase MQKPObjectAssignmentOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPObjectAssignmentOperation.h"

MQKPObjectAssignmentOperation::MQKPObjectAssignmentOperation()
{
	this->_indexKnapsack = 0;
	this->_indexObj = 0;
	this->_deltaFitness = 0;
}

MQKPObjectAssignmentOperation::~MQKPObjectAssignmentOperation()
{
}

void MQKPObjectAssignmentOperation::apply(MQKPSolution &solution)
{
	/* TODO
	 * 1. Asigna el objeto de índice _indexObj a la mochila _indexKnapsack en solution
	 * 2. Actualiza el fitness de solution sumándole _deltaFitness
	 */
	solution.putObjectIn(this->_indexObj, this->_indexKnapsack);	  //Asignamos el objeto
	solution.setFitness(this->_deltaFitness + solution.getFitness()); //Asignamos fitness
}

void MQKPObjectAssignmentOperation::setValues(int indexObject,
											  int indexKnapsack, double deltaFitness)
{
	/* TODO
	 * Guarda los valores pasados como argumentos en las variables miembro
	 */

	this->_indexObj = indexObject;
	this->_indexKnapsack = indexKnapsack;
	this->_deltaFitness = deltaFitness;
}
