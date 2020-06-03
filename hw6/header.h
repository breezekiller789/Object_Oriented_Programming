#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>
#define MaxLine 1024
using namespace std;

int Parser(char **, FILE *);

int rmnewline(char *);

class Student{
    protected:
        char *first_name;
        char *last_name;
};

class English:public Student{
};

class History:public Student{

};

class Math:public Student{
};


