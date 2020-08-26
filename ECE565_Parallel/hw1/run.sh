#! /bin/bash
#script to run the programs

int=1
while(( $int<=10))
do
    ./loop_performance_unrolling 100000000
    let "int++"
done
