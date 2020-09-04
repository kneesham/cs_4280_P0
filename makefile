
output: main.o tree.o util.o
	gcc main.o tree.o util.o -o output

main.o: main.c
	gcc -c main.c

tree.o: tree.c tree.h
	gcc -c tree.c

util.o: util.c util.h
	gcc -c util.c
	
clean:
	rm *.o output

cobj:
	rm *.o
