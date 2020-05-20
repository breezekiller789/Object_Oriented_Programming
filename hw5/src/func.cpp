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

//  Copy Constructor，把值都存一存就可以了。
Bigint::Bigint(const Bigint &cp){
    /* cout << "Copy Constructor..." << endl; */
    this->size = cp.size;
    for(int i=0; i<cp.size; i++){
        this->x[i] = cp.x[i];
        strcpy(this->v[i], cp.v[i]);
    }
    strcpy(this->Final_String, cp.Final_String);
}


//  自己實作setw, setfill，稍微複雜，但是挺簡單的。
//  我的x[]是整數型態，存的是整數，v是二維字元陣列，拿來存字串用的，舉個例：
//  x[0] = 123
//  v[0] = 000000123
//  我這段程式碼，就是要把整數123，轉成字串存起來，然後看有幾個就做幾次，所以
//  外層for loop的upper bound是this->size，跳出for代表所有整數都已經轉完成，
//  下面那個for loop就是把剛剛轉完的所有字串，用strcat()來把他們串在一起，形成
//  我們要的大字串(45 byte)，要注意的是，因為最後的字串是most significant，所以
//  我下面的for loop是用top down approach，從上往下的，這樣才會正確，其實也不一
//  定啦，只要我也順著寫也會對，但是數學上的邏輯會反過來，所以還是弄成我們一般
//  學的表示法來做比較直觀一點。
void Bigint::Combine(){
    for(int i=0; i<this->size; i++){
        char *ptr, tmp[10];
        //  先轉成字串形式
        sprintf(tmp, "%d", x[i]);
        int len = strlen(tmp);
        //  offset代表的是，我要在第幾個位置開始擺，因為前面都會是零。
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
    //  把剛剛做完的字串做merge
    for(int i=this->size-1; i>=0; i--){
        strcat(this->Final_String, v[i]);
    }
    //  最後面要記得擺空字元，不然待會印出來會印出垃圾字元。
    Final_String[45] = 0;
}

//  把v, Final_String做初始化，這是後面加的，因為程式出現bug，印出一堆垃圾字符QQ
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

//  支援物件相加的功能，會呼叫到這裡，代表我前面已經做完字串的處理，傳過來的是
//  我們要的Bigint的字串，這邊就做相加，方法很簡單，就用小學學的加法原理，從最
//  右邊開始加，超過十就進位，把兩數相加的直扣掉10，然後carry_in變一(進位），
//  如果兩個數加上carry_in小於十，就把carry_in改成零，然後直接存值換下一個。
char *Bigint::Add(const char *s1, const char *s2){
    const char *ptr, *qtr;
    char *result = (char *)malloc(sizeof(char) * 46);
    int carry_in = 0;
    ptr = s1;
    qtr = s2;
    for(int i=44; i>=0; i--){
        int val = *(ptr+i) + *(qtr+i) - 2*'0';
        val += carry_in;
        //  兩數相加再加上carry_in超過十，要進位。
        if(val >= 10){
            carry_in = 1;
            val -= 10;
        }
        //  不用進位，carry_in改成0
        else{
            carry_in = 0;
        }
        *(result+i) = val + '0';
    }
    /* cout << result << endl; */
    return result;
}

char *Bigint::Minus(const char *s1, const char *s2){
    char *ptr, *qtr;
    char *result = (char *)malloc(sizeof(char) * 46);
    ptr = strdup(s1);
    qtr = strdup(s2);
    /* cout << ptr << endl; */
    /* cout << qtr << endl; */
    //  相減小於零的話直接回傳零
    if(strcmp(s1, s2) < 0){
        char *ptr = Int2String_Conversion(0);
        return ptr;
    }
    for(int i=44; i>=0; i--){
        int val = *(ptr+i) - *(qtr+i);
        if(val < 0){
            int idx = i-1;
            while(*(ptr+idx) == 0){
                --idx;
            }
            *(ptr+idx) -= 1;
            idx++;
            while(idx < i){
                *(ptr+idx) += 9;
                ++idx;
            }
            *(ptr+idx) += 10;
            val = *(ptr+idx) - *(qtr+i);
            *(result+i) = val + '0';
        }
        else
            *(result+i) = val + '0';
    }
    /* cout << result << endl; */
    return result;
}

char *Bigint::Int2String_Conversion(int amount){
    char num[10], *tmp, *ptr;
    tmp = (char *)malloc(sizeof(char) * 46);
    int i = 0;
    for(i=0; i<46; i++){
        *(tmp+i) = '0';
    }
    *(tmp+i) = 0;
    sprintf(num, "%d", amount);
    int len = strlen(num);
    int offset = 9-len;
    int cnt = 0;
    num[len] = '\0';
    ptr = num;
    while(*ptr != '\0'){
        *(tmp+36+offset+cnt) = *ptr;
        ptr++;
        cnt++;
    }
    *(tmp+36+offset+cnt) = *ptr;
    return tmp;
}

Bigint Bigint::operator+(const Bigint &obj_left){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = strdup(obj_left.Final_String);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = Add(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

Bigint Bigint::operator+(int amount){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = Int2String_Conversion(amount);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = Add(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

Bigint Bigint::operator-(const Bigint &obj_left){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = strdup(obj_left.Final_String);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = Minus(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

Bigint Bigint::operator-(int amount){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = Int2String_Conversion(amount);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = Minus(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

bool Bigint::operator==(const Bigint &in) const{

    int i=0, j=0;
    bool size, _x, _v, _Final_String;
    if(this->size != in.size){
        return false;
    }
    for(i=0; i<this->size; i++){
        if(this->x[i] != in.x[i]){
            return false;
        }

        for(j=0; j<10; j++){
            if(this->v[i][j] != in.v[i][j]){
                return false;
            }
        }
    }
    if(i != this->size){
        return false;
    }
    if(strcmp(this->Final_String, in.Final_String) == 0){
        return true;
    }
    else
        return false;

    return true;
}

bool Bigint::operator!=(const Bigint &in) const{
    return !(in == *this);
}

bool Bigint::operator>(const Bigint &in) const{
    if(strcmp(this->Final_String, in.Final_String) > 0){
        return true;
    }
    //  這個函式是要判斷大於，不是大於等於，如果會走到這一步，代表這兩個字串是
    //  等於，要回傳false
    return false;
}

bool Bigint::operator<(const Bigint &in) const{
    if(strcmp(this->Final_String, in.Final_String) < 0){
        return true;
    }
    //  這個函式是要判斷小於，不是小於等於，如果會走到這一步，代表這兩個字串是
    //  等於，要回傳false
    return false;
}

bool Bigint::operator>=(const Bigint &in) const{
    int ret = strcmp(this->Final_String, in.Final_String);
    if(ret > 0 || ret == 0){
        return true;
    }
    return false;
}

bool Bigint::operator<=(const Bigint &in) const{
    int ret = strcmp(this->Final_String, in.Final_String);
    if(ret < 0 || ret == 0){
        return true;
    }
    return false;
}

ostream & operator<<(ostream &os, const Bigint &in){
    int i=0;
    while(in.Final_String[i] == '0'){
        i++;
    }
    os << &(in.Final_String[i]);
    return os;
}

istream & operator>>(istream &is, Bigint &in){
    int i=0, len, offset;
    char *line = (char *)malloc(sizeof(char) * 46);
    char *ptr = in.Final_String, *qtr;
    for(i=0; i<45; i++){
         *(ptr+i) = '0';
    }
    *(ptr+i) = 0;
    is >> line;
    len = strlen(line);
    *(line+len) = '\0';
    offset = 45 - len;
    i = 0;
    while(*(line+i) != '\0' && i<=len){
        *(ptr+offset+i) = *(line+i);
        ++i;
    }
    *(ptr+offset+i) = '\0';

    return is;
}

