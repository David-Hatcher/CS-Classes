waiting_list : readline.o request.o waiting_list.o
	gcc -o waiting_list readline.o request.o waiting_list.o

waiting_list.o : waiting_list.c 
	gcc -c -Wall waiting_list.c

request.o : request.c request.h
	gcc -c -Wall request.c

readline.o : readline.c readline.h
	gcc -c -Wall readline.c