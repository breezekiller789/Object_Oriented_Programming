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
    Bigint operator+(const Bigint &);       //支援 obj1+obj2+obj3...
    friend Bigint operator+(Bigint, int);   //支援 obj1+1+2+3...
    friend Bigint operator+(int, Bigint);   //支援 1+2+3+obj1...
    Bigint operator-(const Bigint &);       //支援 obj1-obj2-obj3...
    friend Bigint operator-(Bigint, int);   //支援 obj1-1-2-3...
    friend Bigint operator-(int, Bigint);   //支援 1-2-3-obj...
    bool operator==(const Bigint &) const;  //  obj1 == obj2
    friend bool operator==(Bigint &, int);  //  obj1 = 1
    friend bool operator==(int, Bigint &);  //  1 == obj1
    bool operator!=(const Bigint &) const;  //  obj1 != obj2
    friend bool operator!=(Bigint &, int);  //  obj1 != 1
    friend bool operator!=(int, Bigint &);  //  1 != obj1
    bool operator>(const Bigint &) const;   //  obj1 > obj2
    bool operator<(const Bigint &) const;   //  obj1 < obj2
    bool operator>=(const Bigint &)const;   //  obj1 >= obj2
    bool operator<=(const Bigint &)const;   //  obj1 <= obj2
    

    void Combine();
    void Init_Array();
    char *Add(const char *, const char *);
    char *Minus(const char *, const char *);
    char *Int2String_Conversion(int);

    friend ostream & operator<<(ostream &os, const Bigint &in);
    friend istream & operator>>(istream &is, Bigint &in);
};

