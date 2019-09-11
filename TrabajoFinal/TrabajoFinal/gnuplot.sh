#!/bin/bash
FILE1="$1"
FILE2="$2"
FILE3="$3"
FILE4="$4"
FILE5="$5"
OUTPUT="$6"

echo $FILE

cat << _end_ | gnuplot
set terminal postscript eps color
set output "$OUTPUT"
set key right bottom
set xlabel "Tiempo de Ejecuccion"
set ylabel "Fitness"
plot "$FILE1" using 1:2 with lines lc rgb 'green' lw 4 t "B. Aleatoria",\
"$FILE2" using 1:2 with lines lc rgb 'blue' lw 4 t "BL. E.Simple",\
"$FILE3" using 1:2 with lines lc rgb 'black' lw 4 t "BL. M.Pendiente",\
"$FILE4" using 1:2 with lines lc rgb 'red' lw 4 t "B. GRASP",\
"$FILE5" using 1:2 with lines lc rgb 'yellow' lw 4 t "B. Enfriamiento Sim."
_end_
