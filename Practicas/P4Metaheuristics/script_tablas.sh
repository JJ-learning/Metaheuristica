#!/bin/bash

echo "1"
./built/p1.out jeu_100_25_4.txt 3 >> resultados/jeu_100_25_4_1.txt
echo "2"
./built/p1.out jeu_100_25_4.txt 5 >> resultados/jeu_100_25_4_2.txt

echo "3"
./built/p1.out jeu_100_75_2.txt 3 >> resultados/jeu_100_75_2_1.txt
echo "4"
./built/p1.out jeu_100_75_2.txt 5 >> resultados/jeu_100_75_2_2.txt

echo "5"
./built/p1.out jeu_200_25_8.txt 3 >> resultados/jeu_200_25_8_1.txt
echo "6"
./built/p1.out jeu_200_25_8.txt 5 >> resultados/jeu_200_25_8_2.txt

echo "7"
./built/p1.out jeu_200_75_5.txt 3 >> resultados/jeu_200_75_5_1.txt
echo "8"
./built/p1.out jeu_200_75_5.txt 5 >> resultados/jeu_200_75_5_2.txt

#scp gnuplot.sh i42tohej@ts.uco.es:~/meta/P4Meta
#scp script_gnu.sh i42tohej@ts.uco.es:~/meta/P4Meta

scp resultados/*.txt i42tohej@ts.uco.es:~/meta/P4Meta


echo "Esperar a que termine GNUPLOT"
read -n 1 -s -r -p "Press any key to continue"
echo ""

scp i42tohej@ts.uco.es:~/meta/P4Meta/*.eps resultados