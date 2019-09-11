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
plot "$FILE1" using 1:2 t "Current First" w l, "$FILE1" using 1:3 t "Best First" w l, "$FILE1" using 1:4 t "Current Best" w l, "$FILE1" using 1:5 t "Best Best" w l
_end_