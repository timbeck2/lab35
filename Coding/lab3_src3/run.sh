#!/bin/bash          
echo "Compiling..."
gcc -c lab3_lib.c
echo "Linking..."
gcc lab3_lib.o lab3_tests.o -o lab3_tester.out
echo "Testing..."
./lab3_tester.out 2> results.txt