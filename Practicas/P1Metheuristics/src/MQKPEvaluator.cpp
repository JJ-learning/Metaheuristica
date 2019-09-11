/*
 * MQKPEvaluator.cpp
 *
 * Fichero que define los métodos de la clase MQKPEvaluator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPEvaluator.h"
#include "MQKPSolution.h"
#include "MQKPInstance.h"

double MQKPEvaluator::computeFitness(MQKPInstance &instance, MQKPSolution &solution)
{

	double fitness = 0;

	if (instance.getMaxCapacityViolation(solution) > 0)
	{
		fitness = instance.getMaxCapacityViolation(solution) * -1;
	}
	else
	{
		fitness = instance.getSumProfits(solution);
	}
	return fitness;
}



	// for(int i=0; i<solution.getNumObjs(); i++){
	// 	cout<<solution.whereIsObject(i)<<", ";
	// }
	// cout<<" Fitness: "<<fitness<<endl;
