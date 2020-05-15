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

    char **array;
    char line[] = "apple";
    array = (char **)malloc(sizeof(char*) * 1000);
    *(array+1) = strdup(line);
    printf("%s\n", *(array+1));

    return 0;
}
