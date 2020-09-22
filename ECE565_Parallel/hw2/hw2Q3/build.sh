#! /bin/bash

gcc -O3 -o cache_test_write_trffic_only cache_test_write.c -lrt
gcc -O3 -o cache_test_read1_write1 cache_test_read1_write1.c -lrt
gcc -O3 -o cache_test_read2_write1 cache_test_read2_write1.c -lrt
./cache_test_write_trffic_only 10000000
./cache_test_read1_write1 10000000
./cache_test_read2_write1 10000000
