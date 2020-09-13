#include <stdlib.h>
#include <stdio.h>
#include "node.h" // needed for the word capacity.

int isWordInArray( char* word, char ** wordArray) {
    // function that looks for a word in an array. If not it gets added to it.
    int i;
    for (i = 0; i < WORD_CAPACITY; i++) {
        if (wordArray[i] == word) {
            return 1;
        }
        else if (wordArray[i] == NULL) {
            wordArray[i] = word;
        }
    }
    return 0;
}