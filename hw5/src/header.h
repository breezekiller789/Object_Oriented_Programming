#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>
#include <string>
#define MaxLine 1024

using namespace std;

class Bigint{
private:

    int x[5];
    int size;
    char v[5][10];
    char Final_String[46];

public:
    Bigint();
    Bigint(int);
    Bigint(int, int);
    Bigint(int, int, int);
    Bigint(int, int, int, int);
    Bigint(int, int, int, int, int);
    //  Copy Constructor
    Bigint(const Bigint &);
    //  Destructor
    ~Bigint(){
    }
    Bigint operator+(const Bigint &);
    Bigint operator+(int);
    Bigint operator-(const Bigint &);
    Bigint operator-(int);
    bool operator==(const Bigint &) const;
    bool operator!=(const Bigint &) const;
    bool operator>(const Bigint &) const;
    bool operator<(const Bigint &) const;
    bool operator>=(const Bigint &)const;
    bool operator<=(const Bigint &)const;
    

    void Combine();
    void Init_Array();
    char *Add(const char *, const char *);
    char *Minus(const char *, const char *);
    char *Int2String_Conversion(int);

    friend ostream & operator<<(ostream &os, const Bigint &in);
    friend istream & operator>>(istream &is, Bigint &in);
};

