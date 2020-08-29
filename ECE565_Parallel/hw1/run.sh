#! /bin/bash
#script to run the programs

gcc -O2 -o loop_performance loop_performance.c
int=1
while(( $int<=10))
do
    ./loop_performance 10000000
    let "int++"
done
