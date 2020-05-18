#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#define MaxLine 1024

int main(int argc, char *argv[]){

    char *line = (char *)malloc(sizeof(char) * 100);
    fgets(line, 100, stdin);
    char *ptr = line;
    int cnt = 0;
    while(*ptr){
        if(isdigit(*ptr)){
            cnt++;
        }
        ptr++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}
