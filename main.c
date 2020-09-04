// Usage P0 [file] - file is an optional argument.
// P0 		 // read from the keyboard until simulated EOF
// P0 < somefile // same as above except redirecting from somefile instead of keyboard, this tests keyboard input
// P0 somefile   // read from somefile.fs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"
int handleCommandLineArgs(int argc);

int main(int argc, char* argv[]) {

	// TODO: Process command arguments, set up file to work regardless of source,
	//  check if file readable, set the basename for the output file, etc.
	int MAXCHAR = 1000;
	char userIn[MAXCHAR];
	FILE * filePtr;

	if(handleCommandLineArgs(argc)){

		printf(strcat(argv[argc - 1] , ".fs"));
		//filePtr = fopen(strcat(argv[argc - 1] + ".fs"), "r");
		if(filePtr == NULL){
			printf("ERROR: Your file name was incorrect, or does not exist.\n");
		}
		else {
			while (fgets(fileText, MAXCHAR, filePtr) != NULL){
				printf("%s", fileText);
			}
			fclose(filePtr);
		}	
		//fprintf(filePtr, "This is testing for fprintf...\n");
	}
	// TODO: Build the tree




	// Traverse the tree three different ways generating outputs
	return 0;
}

int handleCommandLineArgs(int argc){
	int doesHaveArg = 0;
	if(argc == 1){
		printf("no command line arguments found\n");
	} else if(argc == 2) {
		printf("1 command line argument found\n");
		return 1;
	}
	else {
		printf("There were more command line arguments found than expected.\n");
	}
	return doesHaveArg;
}


