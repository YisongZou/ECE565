#----- Modify CC and CFLAGS as appropriate in your environment
CC = gcc
CFLAGS = -O3 -fopenmp

LIB = -lm -lc

UNITFILES = 

#------------ EXECUTABLE FILES ---------------

histo : histo.o $(UNITFILES)
	$(CC) $(CFLAGS) -o histo histo.o $(UNITFILES) $(LIB)

clean:
	rm -f histo *.o

histo.o : histo.c
	$(CC) $(CFLAGS) -c histo.c $(INCLUDE) 


