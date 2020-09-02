// Usage P0 [file] - file is an optional argument.
// P0 		 // read from the keyboard until simulated EOF
// P0 < somefile // same as above except redirecting from somefile instead of keyboard, this tests keyboard input
// P0 somefile   // read from somefile.fs
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "tree.h"

int main(int argc, char* argv[]) {

	// TODO: Process command arguments, set up file to work regardless of source,
	//  check if file readable, set the basename for the output file, etc.

	int option;
	while((option = getopt(argc,argv, ":if:lrx")) != -1 ){
		printf("%d", option);
		printf("\n");
	}


	// TODO: Build the tree





	// Traverse the tree three different ways generating outputs
	return 0;
}

