#!/bin/sh

uso() {
    echo
    echo "Uso: $0"
    echo
    echo " -h, --help   Muestra el uso"
    echo " -g, --generar   Genera los datos"
    echo " -a, --aleatoria  Metaheuristica aleatoria"
    echo " -l, --local  Metaheuristica busqueda Local"
    echo " -m, --mejorada  Metaheuristica busqueda Mejorada"
    echo
}
argument="$1"

echo "Compilando.."

mkdir build
cd build
cmake ..
make
cd ..

if [[ -z $argument ]] ; then
  raise_error "Error faltan parámetros"
  uso
else
    case $argument in
        -h|--help)
            uso
            ;;
        -g|--generar)
            echo "Generando Archivos"
            ./build/ejecutable g
            ;;
        -a|--aleatoria)
            ./build/ejecutable data1200-400.txt 450 a > /dev/null
            mv output-BA.txt output-BA-100.txt

            ./build/ejecutable data600-400.txt 450 a > /dev/null
            mv output-BA.txt output-BA-200.txt

            ./build/ejecutable data1200-400.txt 450 a > /dev/null
            mv output-BA.txt output-BA-400.txt

            echo "Fin Búsqueda Aleatoria"
            echo "Ejecutando gnuplot"
            sh ./gnuplot.sh output-BA-100.txt output-BA-200.txt output-BA-400.txt busquedaaleatoria.eps
            ;;
        -l|--local)
            ./build/ejecutable data1200-400.txt 450 l > /dev/null
            mv output-BL.txt output-BL-100.txt

            ./build/ejecutable data600-400.txt 450 l > /dev/null
            mv output-BL.txt output-BL-200.txt

            ./build/ejecutable data1200-400.txt 450 l > /dev/null
            mv output-BL.txt output-BL-400.txt

            echo "Fin Búsqueda Local Escalada Simple"
            echo "Ejecutando gnuplot"
            sh ./gnuplot.sh output-BL-100.txt output-BL-200.txt output-BL-400.txt busquedalocalsimple.eps
            ;;
        -m|--mejorada)
            ./build/ejecutable data1200-400.txt 450 m > /dev/null
            mv output-BLM.txt output-BLM-100.txt

            ./build/ejecutable data600-400.txt 450 m > /dev/null
            mv output-BLM.txt output-BLM-200.txt

            ./build/ejecutable data1200-400.txt 450 m > /dev/null
            mv output-BLM.txt output-BLM-400.txt

            echo "Fin Búsqueda Local Escalada Maxima Pendiente"
            echo "Ejecutando gnuplot"
            sh ./gnuplot.sh output-BLM-100.txt output-BLM-200.txt output-BLM-400.txt busquedalocalmejorada.eps
            ;;
        -z|--grasp)
            ./build/ejecutable data1200-400.txt 450 z > /dev/null
            mv output-BLM.txt output-BLM-100.txt

            ./build/ejecutable data600-400.txt 450 z > /dev/null
            mv output-BLM.txt output-BLM-200.txt

            ./build/ejecutable data1200-400.txt 450 z > /dev/null
            mv output-BLM.txt output-BLM-400.txt

            echo "Fin Búsqueda Local Escalada Maxima Pendiente"
            echo "Ejecutando gnuplot"
            sh ./gnuplot.sh output-BLM-100.txt output-BLM-200.txt output-BLM-400.txt busquedalocalmejorada.eps
            ;;
        --clean)
            echo "Elimando Archivos"
            rm -Rf build/
            ;;
        *)
            echo "Parametro no reconocido: ${argument}"
            uso
            ;;
  esac
fi