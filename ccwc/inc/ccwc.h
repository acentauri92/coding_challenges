#ifndef WC_H
#define WC_H

#include <stdio.h>
#include <stdlib.h>

int countBytes(void);
int countLines(void);
int countWords(void);
int countChars(void);

FILE* openFile(char* filename);

#endif // WC_H
