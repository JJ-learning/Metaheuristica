/*
 * MQKPInstance.cpp
 *
 * Fichero que define los métodos de la clase MQKPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPInstance.h"
#include "MQKPSolution.h"

MQKPInstance::MQKPInstance()
{
	_numKnapsacks = 0;
	_numObjs = 0;
	_profits.resize(0);
	_weights.resize(0);
	_capacities.resize(0);
}

MQKPInstance::~MQKPInstance()
{
	for (int i = 0; i < _numObjs; i++)
	{
		_profits[i].clear();
	}
	_profits.clear();
	_weights.clear();
	_capacities.clear();
}

double MQKPInstance::getMaxCapacityViolation(MQKPSolution &solution)
{

	double *sumWeights = new double[this->_numKnapsacks + 1];

	for (int j = 1; j <= this->_numKnapsacks; j++)
	{
		sumWeights[j] = 0;
	}

	for (int i = 0; i < this->_numObjs; i++)
	{
		if (solution.whereIsObject(i) > 0)
		{
			sumWeights[solution.whereIsObject(i)] = sumWeights[solution.whereIsObject(i)] + this->getWeights(i);
		}
	}

	double maxCapacityViolation = 0; //Inicializamos la máxima violación de alguna mochila a 0, que significa que no hay ninguna violación
	int object = 0;
	for (int j = 1; j <= this->_numKnapsacks; j++)
	{
		if ((sumWeights[j] - this->getCapacity(j)) > maxCapacityViolation)
		{
			maxCapacityViolation = sumWeights[j] - this->getCapacity(j);
			object = j;
		}
	}

	delete[] sumWeights;
	return maxCapacityViolation;
}

double MQKPInstance::getSumProfits(MQKPSolution &solution)
{

	double sumProfits = 0.;

	for (int i = 0; i < this->getNumObjs() - 1; i++)
	{
		if (solution.whereIsObject(i) != 0)
		{
			sumProfits += this->getProfits(i, i);
			for (int j = i + 1; j < this->getNumObjs(); j++)
			{ //i+1 para que salte la diagonal
				if (solution.whereIsObject(j) == solution.whereIsObject(i))
				{
					sumProfits += this->getProfits(i, j);
				}
			}
		}
	}

	if (solution.whereIsObject(this->getNumObjs() - 1) != 0)
	{
		sumProfits += this->getProfits(this->getNumObjs() - 1, this->getNumObjs() - 1);
	}
	return sumProfits;
}

void MQKPInstance::readInstance(char *filename, int numKnapsacks)
{
	this->setNumSacks(numKnapsacks);

	ifstream file;
	file.open(filename);

	// Leemos la primera línea
	string aux;
	file >> aux;

	// Leemos la segunda linea(número objetos)
	double numObj;
	file >> numObj;
	this->setNumObj(numObj);

	// Reservamos memoria
	this->_profits.resize(this->getNumObjs());
	for (int i = 0; i < this->getNumObjs(); i++)
	{
		this->_profits[i].resize(this->getNumObjs());
	}
	this->_weights.resize(this->getNumObjs());
	this->_capacities.resize(this->getNumSacks());

	// Leemos los beneficios y pesos
	// Primero leemos la diagonal
	double profits;
	for (int i = 0; i < this->getNumObjs(); i++)
	{
		file >> profits;
		this->setProfits(i, i, profits);
	}
	// Leemos la mitad superior derecha
	for (int i = 0; i < this->getNumObjs() - 1; i++)
	{
		for (int j = i + 1; j < this->getNumObjs(); j++)
		{
			file >> profits;
			this->setProfits(i, j, profits);
			this->setProfits(j, i, profits);
		}
	}
	file >> profits;
	file >> profits;
	for (int i = 0; i < this->getNumObjs(); i++)
	{
		file >> profits;
		this->setWeight(i, profits);
	}
	file.close();

	// Calculamos la capacidad de la mochila
	int sum = 0;
	for (int i = 0; i < this->getNumObjs(); i++)
	{
		sum += this->getWeights(i);
	}
	sum *= 0.8;
	sum /= this->getNumSacks();
	this->setCapacity(0, -1);
	for (int i = 1; i <= this->getNumSacks(); i++)
	{
		this->setCapacity(i, sum);
	}
}
