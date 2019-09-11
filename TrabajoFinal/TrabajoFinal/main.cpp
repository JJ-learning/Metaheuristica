//
//  main.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//  ./build/ejecutable data1200-800.txt 1200 l > /dev/null & ./build/ejecutable data1200-800.txt 1200 m > /dev/null & ./build/ejecutable data1200-800.txt 1200 z > /dev/null & ./build/ejecutable data1200-800.txt 1200 a > /dev/null & ./build/ejecutable data1200-800.txt 1200 e > /dev/null &

#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include "Funciones.hpp"
#include "Datos.hpp" // generarDatos - leerDatos

using namespace std;

int tiempo_ejecuccion;

int main(int argc, const char * argv[]) {
    
    // Creamos los ficheros con los datos
    if(*argv[1] == 'g') {
        generarDatos(400, 800);
        this_thread::sleep_for (chrono::seconds(3));
        generarDatos(600, 800);
        this_thread::sleep_for (chrono::seconds(3));
        generarDatos(1200, 800);
        
        exit(1);
    }

    if( argc != 4  || *argv[1] == 'h') {
        cout << "Procedimiento para introducir los parámetros" << endl;
        cout << "./ejecutable [rutaFichero.txt] [tiempoDeEjeuccion] [Metaheuristica]" << endl;
        cout << "a -> Busqueda Aleatoria" << endl;
        cout << "l -> Busqueda Local Escalada Simple" << endl;
        cout << "m -> Busqueda Local Máxima Pendiente" << endl;
        cout << "z -> Busqueda GRASP" << endl;
        cout << "e -> Enfriamiento Simulado" << endl;
        cout << endl;
        
        exit(1);
    }
    
    // Recogemos el nombre del fichero con los datos
    string nombre_fichero = argv[1];
    
    // Recogemos la duracion de ejecuccion
    tiempo_ejecuccion = atoi(argv[2]);
    
    // Leemos los datos
    vector<Particion> particiones_fichero = leerDatos(nombre_fichero);
    
    // Ejecutamos la metaheurística seleccionada por parámetros.
    switch (*argv[3]) {
        case 'a':
            cout << "Ejecutando búsqueda Aleatoria" << endl;
            ejecutarBusquedaAleatoria(particiones_fichero, "output-BA.txt");
            break;
        case 'l':
            cout << "Ejecutando búsqueda Local Escalada Simple" << endl;
            ejecutarBusquedaLocalEscaladaSimple(particiones_fichero, "output-BL.txt");
            break;
        case 'm':
            cout << "Ejecutando búsqueda Local Máxima Pendiente" << endl;
            ejecutarBusquedaLocalMaximaPendiente(particiones_fichero, "output-BLM.txt");
            break;
        case 'z':
            cout << "Ejecutando GRASP" << endl;
            ejecutarGRASP(particiones_fichero, "output-G.txt");
            break;
        case 'e':
            cout << "Ejecutando Enfriamiento Simulado" << endl;
            ejecutarEnfriamientoSimulado(particiones_fichero, "output-ES.txt");
            break;
        default:
            cout << "No se ha definido ninguna metaheurista por argumentos" << endl;
            cout << " argv[1] = fichero.txt - argv[2] = duracion - argv[3] = Metaheuristica" << endl;
            break;
    }
    
    return 0;
}
