#! /bin/bash
#script to run the programs

gcc -O2 -o loop_performance_unrollimg loop_performance_unrolling.c
int=1
while(( $int<=10))
do
    ./loop_performance_unrolling 10000000
    let "int++"
done
