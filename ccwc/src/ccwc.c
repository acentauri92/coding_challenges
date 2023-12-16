#include "ccwc.h"
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

extern char* optarg;
extern int optind;

int main(int argc, char* argv[]){
    int options;
    char* file;
    while( (options = getopt(argc, argv, "c:l:w:m:")) != -1){
        file = optarg;
        switch(options){
            case 'c':
            //Count bytes in file
                fprintf(stdout, "%d %s\n", countBytes(file), file);             
                break;
            case 'l':
             //Count lines in file
                fprintf(stdout, "%d %s\n", countLines(file), file);
                break;
            case 'w':
             //Count words in file
                fprintf(stdout, "%d %s\n", countWords(file), file);
                break;
            case 'm':
             //Count chars in file
                fprintf(stdout, "%d %s\n", countChars(file), file);
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
    exit(EXIT_SUCCESS);
}

int countBytes(char* file){

    int character, byteCount = 0;
    FILE* pFile = fopen(file, "r");
 
    if (pFile == NULL){
        perror("ERROR: Cannot open file");
        exit(EXIT_FAILURE);
    }
    while((character = fgetc(pFile)) != EOF){
        byteCount++;
    }
    fclose(pFile);
    return byteCount;
}

int countChars(char* file){
    setlocale(LC_ALL, "");

    wchar_t character;
    int charCount = 0;
    FILE* pFile = fopen(file, "r");
 
    if (pFile == NULL){
        perror("ERROR: Cannot open file");
        exit(EXIT_FAILURE);
    }
    while((character = fgetwc(pFile)) != WEOF){
        charCount++;
    }
    fclose(pFile);
    return charCount;
}

int countLines(char* file){
    int character, lineCount = 0;
    FILE* pFile = fopen(file, "r");
    if(pFile == NULL){
        perror("ERROR: Cannot open file");
        exit(EXIT_FAILURE);
    }

    while( (character = fgetc(pFile)) != EOF){
        if(character == '\n')
            lineCount++;
    }
    fclose(pFile);
    return lineCount;

}

int countWords(char* file){
    int character, wordCount = 0;
    int inWord = false;

    FILE* pFile = fopen(file, "r");
    if(pFile == NULL){
        perror("ERROR: Cannot open file");
        exit(EXIT_FAILURE);
    }
    while( (character = fgetc(pFile)) != EOF){

        if(!isspace(character)){
            if(!inWord){
                inWord = true;
                wordCount++;
            }
        }   
                   
        else{
            inWord = false;
        }
    }

    return wordCount;
}
