#!/bin/sh

echo "Ejecutando varias pruebas.."

mkdir build
cd build
cmake ..
make
cd ..

mkdir test-1-400
mkdir test-2-400
mkdir test-1-600
mkdir test-2-600
mkdir test-1-1200
mkdir test-2-1200

cd test-1-400
../build/ejecutable ../data600-800.txt 400 a > /dev/null & ../build/ejecutable ../data400-800.txt 400 l > /dev/null & ../build/ejecutable ../data400-800.txt 400 m > /dev/null & ../build/ejecutable ../data400-800.txt 400 z > /dev/null & 
cd ..

cd test-2-400
../build/ejecutable ../data400-800.txt 400 a > /dev/null & ../build/ejecutable ../data400-800.txt 400 l > /dev/null & ../build/ejecutable ../data400-800.txt 400 m > /dev/null & ../build/ejecutable ../data400-800.txt 400 z > /dev/null & 

cd ..
cd test-1-600
../build/ejecutable ../data600-800.txt 600 a > /dev/null & ../build/ejecutable ../data600-800.txt 600 l > /dev/null & ../build/ejecutable ../data600-800.txt 600 m > /dev/null & ../build/ejecutable ../data600-800.txt 600 z > /dev/null & 

cd ..
cd test-2-600
../build/ejecutable ../data600-800.txt 600 a > /dev/null & ../build/ejecutable ../data600-800.txt 600 l > /dev/null & ../build/ejecutable ../data600-800.txt 600 m > /dev/null & ../build/ejecutable ../data600-800.txt 600 z > /dev/null & 

cd ..
cd test-1-1200
../build/ejecutable ../data1200-800.txt 1200 a > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 l > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 m > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 z > /dev/null & 

cd ..
cd test-2-1200
../build/ejecutable ../data1200-800.txt 1200 a > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 l > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 m > /dev/null & ../build/ejecutable ../data1200-800.txt 1200 z > /dev/null & 
