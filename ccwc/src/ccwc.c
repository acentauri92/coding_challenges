#include "ccwc.h"
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

extern char* optarg;
extern int optind;

FILE* pFile = NULL;

int main(int argc, char* argv[]){
    int options;
    char* file;
    while( (options = getopt(argc, argv, "c:l:w:m:")) != -1){
        file = optarg;
        pFile = openFile(file);
        switch(options){
            case 'c':
            //Count bytes in file
                fprintf(stdout, "%d %s\n", countBytes(), file);             
                break;
            case 'l':
             //Count lines in file
                fprintf(stdout, "%d %s\n", countLines(), file);
                break;
            case 'w':
             //Count words in file
                fprintf(stdout, "%d %s\n", countWords(), file);
                break;
            case 'm':
             //Count chars in file
                fprintf(stdout, "%d %s\n", countChars(), file);
                break;
            default:
                fprintf(stdout, "Usage: %s [ -c|l|w ] [file]\n", argv[0]);
        }
    }
    if(1 == optind){
        fprintf(stdout, "%s", "No options provided.\n");
        fprintf(stdout, "Usage: %s [ -c|l|w ] [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    fclose(pFile);
    exit(EXIT_SUCCESS);
}

int countBytes(void){

    int character, byteCount = 0;
    while((character = fgetc(pFile)) != EOF){
        byteCount++;
    }
    return byteCount;
}

int countChars(void){
    setlocale(LC_ALL, "");

    wchar_t character;
    int charCount = 0;

    while((character = fgetwc(pFile)) != WEOF){
        charCount++;
    }
    return charCount;
}

int countLines(void){
    int character, lineCount = 0;
    while( (character = fgetc(pFile)) != EOF){
        if(character == '\n')
            lineCount++;
    }
    return lineCount;

}

int countWords(void){
    int character, wordCount = 0;
    int inWord = false;

    while( (character = fgetc(pFile)) != EOF){

        if(!isspace(character)){
            if(!inWord){
                inWord = true;
                wordCount++;
            }
        }                      
        else {
            inWord = false;
        }
    }
    return wordCount;
}

FILE* openFile(char* filename){
    pFile = fopen(filename, "r");
 
    if (pFile == NULL){
        perror("ERROR: Cannot open file");
        exit(EXIT_FAILURE);
    }
    return pFile;
}

