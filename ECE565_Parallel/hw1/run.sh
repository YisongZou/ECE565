#! /bin/bash
#script to run the programs

gcc -O3 -o loop_performance_fusion loop_performance_fusion.c
int=1
while(( $int<=10))
do
    ./loop_performance_fusion 100000000
    let "int++"
done
