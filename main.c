// Usage P0 [file] - file is an optional argument.
// P0 		 // read from the keyboard until simulated EOF
// P0 < somefile // same as above except redirecting from somefile instead of keyboard, this tests keyboard input
// P0 somefile   // read from somefile.fs
#include <stdio.h>
#include "node.h"
#include "tree.h"
#include "util.h"
#include "argHandler.h"
#include "fileManager.h"
#include "arrayChecker.h"

int main(int argc, char * argv[]) {

	// TODO: Process command arguments, set up file to work regardless of source,
	//  check if file readable, set the basename for the output file, etc.

	FILE * filePtr;
	
	if(hasProperArgs(argc)){
		// read from cammand line argument filename
		filePtr = openFileWithE(argv[argc - 1]);	
		// printf("filename is : %s\n", filePtr);	
	}
	else {
		// get input from keyboard.
		filePtr = createTempFile();
	}

	node_t * root = buildTree(filePtr);


	// Traverse the tree three different ways generating outputs
	destroyTempFile();
	return 0;
}




