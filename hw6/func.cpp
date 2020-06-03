#include "header.h"

using namespace std;

int rmnewline(char *line){
    char *ptr = line;
    int len=0;
    while(*ptr && *ptr != '\n'){
        ptr++;
        len++;
    }
    *ptr = '\0';
    return len;
}

int Parser(char **words, FILE *fp){
    int i=0;
    char *ptr, *qtr;
    char *line = (char *)malloc(sizeof(char) * MaxLine);

    while(fgets(line, MaxLine, fp) != NULL){
        rmnewline(line);
        ptr = line;
        while(1){
            while(isspace(*ptr)){
                ptr++;
            }
            if(*ptr == '\0')
                break;
            *(words+i) = (char *)malloc(sizeof(char) * strlen(line));
            qtr = *(words+i);
            while(*ptr && !isspace(*ptr)){
                *qtr = *ptr;
                /* printf("qtr = %c\tptr = %c\n", *qtr, *ptr); */
                ptr++;
                qtr++;
            }
            /* printf("%s\n", *(words+i)); */
            i++;
            if(isspace(*ptr)){
                while(isspace(*ptr)){
                    ptr++;
                }
                if(*ptr == '\0')
                    break;
                else
                    continue;
            }
            else
                break;
        }
    }


    return i;
}


