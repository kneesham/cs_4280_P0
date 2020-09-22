#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "globals.h"


int getNumberOfWords(char * string) {
	int wordCount = 0;
	int isNextSpace = 0;

	for(int i = 0; i < strlen(string); i++){
		if (isalnum(string[i])) {
			isNextSpace = 0;
		}	
		if (isspace(string[i]) && !isNextSpace ) {

			if (string[i] != '\0' && isspace(string[i + 1])) {
				isNextSpace = 0;
				continue;
			}
			
		 	wordCount++;
		}		
	}
	return wordCount + 1;
}


void getWords( char * wordArray[], char * string ){

    char * pch;
    pch = strtok (string, " ");
    

    for (int i = 0; pch != NULL; i++) {
        wordArray[i] = pch;
        uniqueWordCount++;
        pch = strtok (NULL, " ");
    }
}



// char * getTextFromFile(FILE * filePtr) {
// 		char * textToBuildTree = malloc(0 * sizeof(char));
		
// 		if(filePtr == NULL){
// 			printf("ERROR: Your file does not exist, OR  was unreadable.\n");
// 		}
// 		else {
// 			int character; 
// 			int i = 0;
// 			int spaceCnt = 0;
// 			do {
// 				character = fgetc(filePtr);

// 				if( isspace(character)){
// 					 if(character == '\n') character = ' ';
// 					 if(spaceCnt >= 1) continue;
// 					 spaceCnt += 1;
// 				}
// 				else { spaceCnt = 0; }

// 				int oldSize = strlen(textToBuildTree) * sizeof(char); // old size of the character array.
// 				textToBuildTree = realloc(textToBuildTree, (1 * sizeof(char) + oldSize) );
// 				textToBuildTree[i] = character;
// 				i = i + 1;

// 			} while(character != EOF);

// 			textToBuildTree[i - 1] = '\0';

// 			fclose(filePtr);
// 		}

// 	return textToBuildTree;	

// }

// int cFileExists(char * file){
//     // try to open file to read 
//     FILE * file;

//     if (file = fopen(file, "r")){
//         fclose(file);
//         return 1;
//     }
//     else {
//         // perror("/file is not readable OR your file does not exists.");
//     }
//     return 0;
// }

