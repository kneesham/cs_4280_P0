#include <stdio.h>
#include <string.h>


FILE * createTempFile() {
    FILE * tempFile = fopen("./temp.fs", "w+");
	char  userInput[200];

	printf("\nPlease enter a string to build the tree with: ");
	fgets(userInput, 200, stdin);

	fputs(userInput, tempFile);
	fclose(tempFile);
	return  fopen("./temp.fs", "r");
}

void destroyTempFile(){
    remove("./temp.fs");
}

FILE * openFileWithE(char * fileName) {
	FILE * filePtr;
	char fileWithE[ strlen(fileName) + strlen(".fs") + 1] ;
	strcpy(fileWithE, fileName);
	strcat(fileWithE, ".fs");

	printf("opening: %s\n", fileWithE);
	filePtr = fopen(fileWithE, "r");
	return filePtr;
}