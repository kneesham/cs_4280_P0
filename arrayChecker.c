#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "node.h" // needed for the word capacity.

int isWordInArray( char* word, char ** wordArray) {
    // function that looks for a word in an array. If not it gets added to it.
    int i;
    for (i = 0; i < WORD_CAPACITY; i++) {
        if (!strcmp(wordArray[i], word)) {
            printf("yes!\n");
            break;
        }

    }
    return 0;
}