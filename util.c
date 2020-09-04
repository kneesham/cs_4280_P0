#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 


char * getTextFromFile(char * fileName) {
		FILE * filePtr;
        fileName = strcat(fileName, ".fs");
		filePtr = fopen(fileName, "r");
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

// int cFileExists(char * filename){
//     // try to open file to read 
//     FILE * file;

//     if (file = fopen(filename, "r")){
//         fclose(file);
//         return 1;
//     }
//     else {
//         // perror("/file is not readable OR your file does not exists.");
//     }
//     return 0;
// }

