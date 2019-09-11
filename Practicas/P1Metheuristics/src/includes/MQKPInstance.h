/**
 * MQKPInstance.h
 * 
 * Fichero que define la clase MQKPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef __MQKPINSTANCE_H__
#define __MQKPINSTANCE_H__

#ifndef __MQKPSOLUTION_H__
#include "MQKPSolution.h"
#else
class MQKPSolution;
#endif

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
/**
 * Clase que almacena la información de una instancia del problema MQKP
 */
class MQKPInstance
{
  protected:
	/*TODO Definir las variables miembro
	 * _numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 * _numObjs Entero donde se almacenará el número de objetos del problema
	 * _profits Matriz donde se van a almacenar los beneficios de los objetos según lo indicado arriba. HAY QUE RESERVAR SU MEMORIA
	 * _weights Vector con los pesos de los objetos. HAY QUE RESERVAR SU MEMORIA
	 * _capacities Vector con las capacidades de las mochilas. HAY QUE RESERVAR SU MEMORIA. Para evitar problemas, reservadlo con capacidad (1 + numKnapsacks) y utilizadlo desde el índice 1 en adelante
	 */
	int _numKnapsacks;
	int _numObjs;
	vector<vector<float> > _profits;
	vector<float> _weights;
	vector<float> _capacities;

  public:
	/**
	 * Constructor por defecto
	 */
	MQKPInstance();

	/**
	 * Destructor
	 */
	~MQKPInstance();

	/**
	 * Función de lectura de un fichero de entrada
	 * @param[in] filename Nombre del fichero donde están los datos de la instancia
	 * @param[in] numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 */
	void readInstance(char *filename, int numKnapsacks);

	//TODO declarar los métodos (y definirlos en MQKPInstance.cpp) que devuelvan la información que se consulte acerca de la instancia del problema
	//Entre otros getNumObjs() y getNumKnapsacks()

	/**
	 * Función que devuelve por cuanto se viola la capacidad de la mochila que está más cargada de más
	 * @param[in] solution Referencia a un objeto que representa una solución al problema
	 * @return Máxima violación de las capacidades de las mochilas
	 */
	double getMaxCapacityViolation(MQKPSolution &solution);

	/**
	 * Función que calcula la suma de beneficios individuales y cuadráticos de los objetos en mochilas
	 * @param[in] solution Referencia a un objeto que representa una solución al problema
	 * @return Suma de los beneficios individuales y cuadráticos de los objetos en las mochilas
	 */
	double getSumProfits(MQKPSolution &solution);

	/**
	 *	Observadores de las variables privadas de la clase
	 */
	inline int getNumSacks()
	{
		return this->_numKnapsacks;
	}

	inline int getNumObjs()
	{
		return this->_numObjs;
	}

	inline float getProfits(int row, int col)
	{
		return this->_profits[row][col];
	}

	inline float getWeights(int i)
	{
		return this->_weights[i];
	}

	inline double getCapacity(int pos)
	{
		return this->_capacities[pos];
	}

	/**
	 *	Modificadores de las variables privadas de la clase
	 */
	inline void setNumObj(double numObj)
	{
		this->_numObjs = numObj;
	}

	inline void setNumSacks(int numSacks)
	{
		this->_numKnapsacks = numSacks;
	}

	inline void setProfits(int row, int col, int value)
	{
		this->_profits[row][col] = value;
	}

	inline void setWeight(int pos, float value)
	{
		this->_weights[pos] = value;
	}

	inline void setCapacity(int pos, float value)
	{
		this->_capacities[pos] = value;
	}
};

#endif
