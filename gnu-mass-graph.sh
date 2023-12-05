#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Input file name
input_file=$1

# output file name
output_file="${input_file%.out}.png"


# Gnuplot script to generate the plot
gnuplot <<EOF
set terminal pngcairo enhanced font 'Verdana,12'
set output '$output_file'

# Assuming each column represents a separate object
plot for [i=1:*] '$input_file' using 0:i with lines notitle
EOF

echo "Plot generated: $output_plot"

