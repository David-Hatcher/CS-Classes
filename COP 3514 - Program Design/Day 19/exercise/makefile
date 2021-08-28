prime: primetest.o prime.o
	gcc -o prime primetest.o prime.o

primetest.o: primetest.c prime.h
	gcc -c primetest.c

prime.o: prime.c prime.h
	gcc -c prime.c