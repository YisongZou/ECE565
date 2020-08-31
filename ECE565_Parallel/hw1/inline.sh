#! /bin/bash
#script to run the programs

g++ -O3 -o func_no_inlining func_no_inlining.cpp
int=1
while(( $int<=10))
do
    ./func_no_inlining 10000000
    let "int++"
done
