
output: main.o tree.o util.o argHandler.o fileManager.o arrayChecker.o
	gcc main.o tree.o util.o argHandler.o fileManager.o arrayChecker.o -o output

argHandler.o: argHandler.c argHandler.h
	gcc -c argHandler.c
	
main.o: main.c
	gcc -c main.c

tree.o: tree.c tree.h
	gcc -c tree.c

util.o: util.c util.h
	gcc -c util.c
fileManager.o: fileManager.c fileManager.h
	gcc -c fileManager.c

arrayChecker.o: arrayChecker.c arrayChecker.h
	gcc -c arrayChecker.c

clean:
	rm *.o output

cobj:
	rm *.o
