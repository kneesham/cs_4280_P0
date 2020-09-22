#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "fileManager.h"
#include "globals.h"
#include "arrayChecker.h"
#include "util.h"

int uniqueWordCount = 0;

int compare(char * str1, char * str2){
    if(str1[0] > str2[0]){
        return 1;
    }
    if(str1[0] < str2[0]) { // go left
        return -1;
    }
    return 0;
}

void display_tree(node_t* nd)
{
    if (nd == NULL)
        return;
    /* display node data */
    printf("%s",nd->words);
    if(nd->left != NULL)
        printf("(L:%s)",nd->left->words);
    if(nd->right != NULL)
        printf("(R:%s)",nd->right->words);
    printf("\n");
 
    display_tree(nd->left);
    display_tree(nd->right);
}

node_t * createNode(char* word){
    
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    if(new_node == NULL){
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->words = word; 
    new_node->numWords = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node_t* insertNode(node_t *root, char* word) {
    if(root == NULL){
        root = createNode(word);
    }
    else {
        int is_left  = 0;
        int r        = 0;
        node_t * cursor = root;
        node_t * prev   = NULL;
 
        while(cursor != NULL) {
            r = compare(word,cursor->words);
            prev = cursor;
            if(r < 0) {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(r > 0) {
                is_left = 0;
                cursor = cursor->right;
            }
            else if(r == 0){
                //Todo: concatontate the "words" string....
                char updatedWord[ strlen(cursor->words) + strlen(word) + 1];
	            strcpy(updatedWord, cursor->words);
	            strcat(updatedWord, word);
                cursor->words = updatedWord;
            }
        }

        if(is_left){
            prev->left = createNode(word);
        }
        else {
            prev->right = createNode(word);
        }

    }
    return root;
}

node_t * buildTree(FILE * file) {
    char * textFromFile = getTextFromFile(file);
    int numWords = getNumberOfWords(textFromFile);
    char * wordArray[numWords];
    node_t * root = NULL;

    getWords(wordArray, textFromFile);

    for (int i = 0; i < uniqueWordCount; i++){
        // printf("adding word: %s\n", wordArray[i]);
        root = insertNode(root, wordArray[i]);
    }

    display_tree(root);
    return root;
}


