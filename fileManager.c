#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>


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
	char fileWithE[ strlen(fileName) + strlen(".fs") + 1];
	strcpy(fileWithE, fileName);
	strcat(fileWithE, ".fs");

	printf("opening: %s\n", fileWithE);
	filePtr = fopen(fileWithE, "r");
	return filePtr;
}

char * getTextFromFile(FILE * filePtr) {
		char * textToBuildTree = malloc(0 * sizeof(char));
		
		if(filePtr == NULL){
			printf("ERROR: Your file does not exist, OR  was unreadable.\n");
		}
		else {
			int character; 
			int i = 0;
			int spaceCnt = 0;
			do {
				character = fgetc(filePtr);

				if( isspace(character)){
					 if(character == '\n') character = ' ';
					 if(spaceCnt >= 1) continue;
					 spaceCnt += 1;
				}
				else { spaceCnt = 0; }

				int oldSize = strlen(textToBuildTree) * sizeof(char); // old size of the character array.
				textToBuildTree = realloc(textToBuildTree, (1 * sizeof(char) + oldSize) );
				textToBuildTree[i] = character;
				i = i + 1;

			} while(character != EOF);

			textToBuildTree[i - 1] = '\0';

			fclose(filePtr);
		}

	return textToBuildTree;	

}