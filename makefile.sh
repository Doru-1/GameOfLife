#!/bin/bash

gcc main.c common.c task1.c task2.c task3.c

for i in {0..20}; do
	input="InputData/data${i}.in"
	output="OutputData/data${i}.out"

	./a.out "$input" "$output"
done

echo "Terminat."