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

class Student{
    private:
        char first_name[21];
        char last_name[21];
        char course[10];

    protected:
        void init(char *fn, char *ln, char *subject);

    public:
        void info(FILE *);
        char *Get_Course();
        virtual int Get_Final_Exam_Grade() = 0;
        virtual float Get_Final_Average() = 0;
        virtual char Get_Letter_Grade() = 0;
};

class English:public Student{
    private:
        int English_Grade[4];

    public:
        English(int *Grades, char *fn, char *ln, char *subject);
        int Get_Final_Exam_Grade();
        float Get_Final_Average();
        char Get_Letter_Grade();
};

class History:public Student{
    private:
        int History_Grade[3];

    public:
        History(int *Grades, char *fn, char *ln, char *subject);
        int Get_Final_Exam_Grade();
        float Get_Final_Average();
        char Get_Letter_Grade();
};

class Math:public Student{
    private:
        int Math_Grade[8];

    public:
        Math(int *Grades, char *fn, char *ln, char *subject);
        int Get_Final_Exam_Grade();
        float Get_Final_Average();
        char Get_Letter_Grade();
};


void Export_Result_File(FILE *, Student **, int,char [3][10]);
void Print_Result(FILE *, Student **, int, const char *);
void Parser(int, FILE *, Student **);
int Get_First_Names(const char *, char *);
void Get_Last_Names(const char *, char *);
void Get_Subject(const char *, char *);
int rmnewline(char *);
