//
//  GenerarData.cpp
//  TrabajoFinal Metaheuristica
//
//  Created by Jose Torronteras - Juan José Méndez - Adrían López on 09/05/2019.
//

#include "Datos.hpp"

void generarDatos(int M, int N)
{
    // Declaramos las variables principales
    vector<vector <int> > matriz;
    string output_fichero;
    
    // Declaramos el nombre del fichero en función del tamaño de la matriz
    output_fichero = "data" + to_string(M) + "-" + to_string(N) + ".txt";
    
    ofstream out_file(output_fichero);
    cout << "Escribiendo en el archivo: " << output_fichero << endl;
    
    // Creamos la semilla
    srand (static_cast<unsigned int>(time(NULL)));
    
    for (int i = 0; i < M; ++i) {
        std::vector<int> tmp;
        for (int j = 0; j < N; ++j) {
            tmp.push_back(rand() % 100);
        }
        matriz.push_back(tmp); // Rellenamos la matriz
    }
    
    // La primera fila del fichero contiene la información de la matriz
    out_file << M << " " << N << "\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            out_file << matriz[i][j] << " "; // Escribimos la matriz
        }
        out_file << "\n";
    }
    
    // Cerramos el fichero
    out_file.close();
}

vector<Particion> leerDatos(const string nombreFichero)
{
    vector<Particion> particiones_fichero;
    ifstream inFile(nombreFichero);
    if(!inFile.is_open()){
        cout << "No se ha encontrado el fichero" << endl;
        exit(-1);
    }
    int M, N;
    
    // Recogemos el tamaño de la matriz de datos
    inFile >> M >> N;
    
    for (int i = 0; i < M; ++i) {
        vector<int> elementos_tmp;
        int tmp;

        for (int j = 0; j < N; ++j) {
            inFile >> tmp;
            elementos_tmp.push_back(tmp);
        }
        
        Particion P(elementos_tmp); // Introducimos los nuevos datos en una nueva Partición
        particiones_fichero.push_back(P);
    }
    
    return particiones_fichero;
}
