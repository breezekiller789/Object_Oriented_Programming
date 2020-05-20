#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#define MaxLine 1024

void abc(int a, int b){
    b = b*3 + a;
    printf("a = %d, b= %d\n", a, b);
}

int main(int argc, char *argv[]){

    int a = 1;
    int b = ++a;
    abc(a++, --b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
