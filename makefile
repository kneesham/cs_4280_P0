
output: main.o tree.o
	gcc main.o tree.o -o output

main.o: main.c
	gcc -c main.c

tree.o: tree.c tree.h
	gcc -c tree.c

clean:
	rm *.o output

cobj:
	rm *.o
