#ifndef NODE_H
#define NODE_H
#define WORD_CAPACITY 50

typedef struct {
    char * words[WORD_CAPACITY]; // 50 words per node.
    struct node_t *left;
    struct node_t *right;
} node_t;

#endif


