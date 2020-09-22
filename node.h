#ifndef NODE_H
#define NODE_H
#define WORD_CAPACITY 50

typedef struct node_t {
    char * words;               // string of words at the node.
    int numWords;               // used to keep track of the index of a given word in "words"
    struct node_t * left;       // smaller words.
    struct node_t * right;      // bigger words.
} node_t;


#endif


