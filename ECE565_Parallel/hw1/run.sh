#! /bin/bash
#script to run the programs

gcc -O3 -o loop_performance_strip_mining loop_performance_strip_mining.c
int=1
while(( $int<=10))
do
    ./loop_performance_strip_mining 100000000
    let "int++"
done
