#!/bin/bash
make clean
make
if [ -f test.out ]
then
    rm test.out
fi
./histo uiuc.pgm > test.out
echo "validate normal..."
diff test.out validation.out
rm test.out
echo "validate locks..."
./histo_locks uiuc.pgm > test.out
diff test.out validation.out
rm test.out
echo "validate atomic..."
./histo_atomic uiuc.pgm > test.out
diff test.out validation.out
rm test.out
echo "validate creative..."
./histo_creative uiuc.pgm > test.out
diff test.out validation.out
rm test.out
echo "validation succeed!"
