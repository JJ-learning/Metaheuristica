#!/bin/bash
FILE1="$1"
OUTPUT="$2"

echo $FILE1

cat << _end_ | gnuplot
set terminal postscript eps color
set output "$OUTPUT"
set key right bottom
set xlabel "Iteration"
set ylabel "Fitness"
plot "$FILE1" using 1:2 t "_currentSA" w l, "$FILE1" using 1:3 t "_bestSA" w l
_end_

