#ifndef FILEMANAGER_H 
#define FILEMANAGER_H 

FILE * createTempFile();
void destroyTempFile();
FILE * openFileWithE(char *);
char * getTextFromFile(FILE *);

#endif