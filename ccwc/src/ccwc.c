#include "ccwc.h"
#include <unistd.h>
#include <errno.h>

extern char* optarg;
extern int optind;

int main(int argc, char* argv[]){
    int options;
    char* file;
    while( (options = getopt(argc, argv, "c:")) != -1){
        switch(options){
            case 'c':
            //Count bytes in file
                file = optarg;
                fprintf(stdout, "%d %s\n", countBytes(file), file);             
                break;
            default:
                fprintf(stdout, "Usage: %s [-c] [file]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if(1 == optind){
        fprintf(stdout, "%s", "No options provided.\n");
        fprintf(stdout, "Usage: %s [-c] [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
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
    return byteCount;
}