// Usage P0 [file] - file is an optional argument.
// P0 		 // read from the keyboard until simulated EOF
// P0 < somefile // same as above except redirecting from somefile instead of keyboard, this tests keyboard input
// P0 somefile   // read from somefile.fs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#include "tree.h"
#include "util.h"


int hasProperArgs(int argc);


int main(int argc, char* argv[]) {

	// TODO: Process command arguments, set up file to work regardless of source,
	//  check if file readable, set the basename for the output file, etc.
	char * fileText;
	
	if(hasProperArgs(argc)){
		char * fileName = argv[argc - 1];
		node_t * root = buildTree(fileName);


	}
	else {
		//get input from keyboard.

	}
	// TODO: Build the tree


	// Traverse the tree three different ways generating outputs
	return 0;
}

int hasProperArgs(int argc){
	int doesHaveArg = 0;
	if(argc == 1) {
		// printf("no command line arguments found\n");
		return 0;
	} else if(argc == 2) {
		// printf("1 command line argument found\n");
		return 1;
	}
	else {
		printf("ERROR: There were more command line arguments found than expected.\n");
	}
	return doesHaveArg;
}


