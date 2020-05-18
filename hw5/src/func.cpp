#include "header.h"

using namespace std;

Bigint::Bigint(){
    this->size = 5;
    Init_Array();
    strcpy(this->Final_String, "0");
}
Bigint::Bigint(int x0){
    x[0] = x0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    this->size = 5;
    Init_Array();
    Combine();
}
Bigint::Bigint(int x0, int x1){
    x[0] = x0;
    x[1] = x1;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    this->size = 5;
    Init_Array();
    Combine();
}
Bigint::Bigint(int x0, int x1, int x2){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    x[3] = 0;
    x[4] = 0;
    this->size = 5;
    Init_Array();
    Combine();
}
Bigint::Bigint(int x0, int x1, int x2, int x3){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    x[3] = x3;
    x[4] = 0;
    this->size = 5;
    Init_Array();
    Combine();
}
Bigint::Bigint(int x0, int x1, int x2, int x3, int x4){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    x[3] = x3;
    x[4] = x4;
    this->size = 5;
    Init_Array();
    Combine();
}

Bigint::Bigint(const Bigint &cp){
    cout << "Copy Constructor..." << endl;
    this->size = cp.size;
    for(int i=0; i<cp.size; i++){
        this->x[i] = cp.x[i];
        strcpy(this->v[i], cp.v[i]);
    }
    strcpy(this->Final_String, cp.Final_String);
}

Bigint Bigint::operator+(const Bigint &obj_left){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = strdup(obj_left.Final_String);
    char *ptr;
    cout << s1 << endl;
    cout << s2 << endl;
    ptr = Add(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

void Bigint::Combine(){
    for(int i=0; i<this->size; i++){
        char *ptr, tmp[10];
        sprintf(tmp, "%d", x[i]);
        int len = strlen(tmp);
        int offset = 9 - len;
        int cnt=0;
        tmp[len] = '\0';
        ptr = tmp;
        while(*ptr != '\0'){
            v[i][offset+cnt] = *ptr;
            ptr++;
            cnt++;
        }
        /* printf("%s\n", v[i]); */
    }
    for(int i=this->size-1; i>=0; i--){
        strcat(this->Final_String, v[i]);
    }
    Final_String[45] = 0;
}

void Bigint::Init_Array(){
    int i, j;
    for(i=0; i<this->size; i++){
        for(j=0; j<9; j++){
            v[i][j] = '0';
        }
        v[i][j] = 0;
    }
    for(i=0; i<45; i++){
        Final_String[i] = 0;
    }
}

char *Bigint::Add(const char *s1, const char *s2){
    const char *ptr, *qtr;
    char *result = (char *)malloc(sizeof(char) * 46);
    ptr = s1;
    qtr = s2;
    for(int i=44; i>=0; i--){
        int val = *(ptr+i) + *(qtr+i) - 2*'0';
        *(result+i) = val + '0';
    }
    cout << result << endl;
    return result;
}


ostream & operator<<(ostream &os, const Bigint &in){
    os << in.Final_String;
    return os;
}

istream & operator>>(istream &is, Bigint &in){
    int i=0, cnt=0;
    while(is >> in.x[i]){
        cnt++;
        i++;
    }
    in.size = cnt;
    in.Init_Array();
    in.Combine();
    return is;
}

