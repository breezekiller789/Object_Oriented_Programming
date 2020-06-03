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


int Get_First_Names(const char *, char *);
void Get_Last_Names(const char *, char *);
void Get_Subject(const char *, char *);

int rmnewline(char *);

class Student{
    protected:
        char first_name[20];
        char last_name[20];
        char course[10];
        int English_Grade[4];
        int History_Grade[3];
        int Math_Grade[8];

    public:
        virtual void info() = 0;
};

class English:public Student{
    public:
        English(int *Grades, char *fn, char *ln, char *subject);
        void info();
};

class History:public Student{
    public:
        History(int *Grades, char *fn, char *ln, char *subject);
        void info();
};

class Math:public Student{
    public:
        Math(int *Grades, char *fn, char *ln, char *subject);
        void info();
};


void Parser(int, FILE *, Student **);
