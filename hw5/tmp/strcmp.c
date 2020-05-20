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

    char *ptr = "123";
    char *qtr = "834";

    printf("%d\n", strcmp(qtr, ptr));

    return 0;
}
