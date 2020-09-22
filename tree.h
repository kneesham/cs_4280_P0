
#ifndef TREE_H 
#define TREE_H  

node_t * buildTree(FILE *);
// void printPreorder(node_t *);
// void printInorder(node_t *);
// void printPostorder(node_t *); 
node_t * create_node(char*);
void getWords( char **, char *);
node_t* insertNode(node_t * , char*);

#endif

