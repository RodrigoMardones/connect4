output:main.o
	gcc main.o -o salida

main.o: main.c
	gcc -c main.c