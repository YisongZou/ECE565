#! /bin/bash
#script to run the programs

g++ -O3 -o func_inlining func_inlining.cpp
int=1
while(( $int<=10))
do
    ./func_inlining 10000000
    let "int++"
done
