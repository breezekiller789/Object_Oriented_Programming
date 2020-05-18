/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <ctype.h> */
/* #include <unistd.h> */
/* #include <math.h> */
/* #include <fcntl.h> */
/* #include <limits.h> */
/* #include <iostream> */
/* #include <string> */
/* #define MaxLine 1024 */

using namespace std;

class Bigint{
private:

    int x[5];
    int size;
    char v[5][10];
    char Final_String[46];

public:
    Bigint();
    Bigint(int x0);
    Bigint(int x0, int x1);
    Bigint(int x0, int x1, int x2);
    Bigint(int x0, int x1, int x2, int x3);
    Bigint(int x0, int x1, int x2, int x3, int x4);


    void Add();
    void Init_Array();

    friend ostream & operator<<(ostream &os, const Bigint &in);
    friend istream & operator>>(istream &is, Bigint &in);
};
Bigint::Bigint(){
    this->size = 0;
    Init_Array();
    strcpy(this->Final_String, "0");
}
Bigint::Bigint(int x0){
    x[0] = x0;
    this->size = 1;
    Init_Array();
    Add();
}
Bigint::Bigint(int x0, int x1){
    x[0] = x0;
    x[1] = x1;
    this->size = 2;
    Init_Array();
    Add();
}
Bigint::Bigint(int x0, int x1, int x2){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    this->size = 3;
    Init_Array();
    Add();
}
Bigint::Bigint(int x0, int x1, int x2, int x3){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    x[3] = x3;
    this->size = 4;
    Init_Array();
    Add();
}
Bigint::Bigint(int x0, int x1, int x2, int x3, int x4){
    x[0] = x0;
    x[1] = x1;
    x[2] = x2;
    x[3] = x3;
    x[4] = x4;
    this->size = 5;
    Init_Array();
    Add();
}
//  36 37 38 39 40 41 42 43 44
void Bigint::Add(){
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
    in.Add();
    return is;
}

int main(int argc, char *argv[]){
    Bigint x(1000, 24123, 111, 33333333, 123456789);
    Bigint y(321000, 5313, 111, 3119033, 123456789);
    Bigint n(0001, 01, 00100001, 00000001, 1);
    Bigint z;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << n << endl;
    return 0;
}
