#include "header.h"

using namespace std;

Bigint::Bigint(){
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    x[4] = 0;
    this->size = 5;
    Init_Array();
    Combine();
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

//  做字串的減法，完全就依照小學學的減法來實作，稍微有點複雜。
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

    //  這個for在做全部的減法，從最後面開始往前，所以i從44開始往下。
    for(int i=44; i>=0; i--){
        //  兩數相減。
        int val = *(ptr+i) - *(qtr+i);
        //  若相減小於零，代表要往前去借。
        if(val < 0){
            //  idx是往前走的索引值，從i-1開始往前走。
            int idx = i-1;
            //  如果前面都是零，那就要一直往前走，走到不是零為止。
            while(*(ptr+idx) == 0){
                --idx;
            }
            //  走到這裡代表找到不為零的，該值減一。
            *(ptr+idx) -= 1;
            //  減完之後，就又要往回頭路走，一路走回去，走回去的每一個地方都給
            //  他加9，直到回到原始位置為止。
            idx++;
            while(idx < i){
                *(ptr+idx) += 9;
                ++idx;
            }
            //  回到原始位置，該值加10
            *(ptr+idx) += 10;
            val = *(ptr+idx) - *(qtr+i);
            *(result+i) = val + '0';
        }
        //  如果相減大於零，最簡單，直接存就好。
        else
            *(result+i) = val + '0';
    }
    /* cout << result << endl; */
    return result;
}

//  把整數轉成45byte的字串。
char *Bigint::Int2String_Conversion(int amount){
    char num[10], *tmp, *ptr;
    tmp = (char *)malloc(sizeof(char) * 46);
    int i = 0;
    //  全部都先放零。
    for(i=0; i<46; i++){
        *(tmp+i) = '0';
    }
    *(tmp+i) = 0;               //最後放空字元。
    sprintf(num, "%d", amount); //把整數轉成字串。
    int len = strlen(num);      //拿字串長度，待會用得到。
    int offset = 9-len;         //offset代表待會要從哪一個位置開始擺。
    int cnt = 0;                //純粹一個索引值。
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

//  把兩個物件的Bigint字串取出來，丟給Add()去做加法。
Bigint Bigint::operator+(const Bigint &obj_left){
    Bigint ret;
    char *s1 = strdup(this->Final_String);
    char *s2 = strdup(obj_left.Final_String);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = Add(s1, s2);
    //  Add會回傳加完之後的字串，把它存起來，回傳。
    strcpy(ret.Final_String, ptr);
    return ret;
}

//  支援obj+1+2+3...
//  我會呼叫Int2String_Conversion()來幫我把整數轉成45byte的字串，接下來就呼叫Add()
Bigint operator+(Bigint in, int amount){
    Bigint ret;
    char *s1 = strdup(in.Final_String);
    char *s2 = in.Int2String_Conversion(amount);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = in.Add(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

//  支援1+2+3+obj...
//  跟上面基本上一樣，只是字串順序反過來而已。
Bigint operator+(int amount, Bigint in){
    Bigint ret;
    char *s1 = in.Int2String_Conversion(amount);
    char *s2 = strdup(in.Final_String);
    char *ptr;
    ptr = in.Add(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

//  支援obj+obj1+obj2...
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

//  支援obj+1+2+3...
Bigint operator-(Bigint in, int amount){
    Bigint ret;
    char *s1 = strdup(in.Final_String);
    char *s2 = in.Int2String_Conversion(amount);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = in.Minus(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

//  支援1+2+3+obj...
Bigint operator-(int amount, Bigint in){
    Bigint ret;
    char *s1 = in.Int2String_Conversion(amount);
    char *s2 = strdup(in.Final_String);
    char *ptr;
    /* cout << s1 << endl; */
    /* cout << s2 << endl; */
    ptr = in.Minus(s1, s2);
    strcpy(ret.Final_String, ptr);
    return ret;
}

//  obj1 == obj2
//  這邊我逐步檢查是否一樣，只要被抓到不一樣的，直接回傳false，不然就繼續檢查。
bool Bigint::operator==(const Bigint &in) const{

    int i=0, j=0;
    bool size, _x, _v, _Final_String;
    if(this->size != in.size){
        return false;
    }
    for(i=0; i<this->size; i++){
        //  一個值一個值比，一旦不一樣就回傳false
        if(this->x[i] != in.x[i]){
            return false;
        }

        //  v不一樣也回傳false
        if(strcmp(this->v[i], in.v[i]) != 0){
            return false;
        }
    }
    //  檢查Bigint要用的字串。
    if(strcmp(this->Final_String, in.Final_String) == 0){
        return true;
    }
    else
        return false;

    return true;
}

bool operator==(Bigint &in, int amount){
    char *s1 = strdup(in.Final_String);
    char *s2 = in.Int2String_Conversion(amount);
    if(strcmp(s1, s2) == 0){
        return true;
    }
    else
        return false;
    return true;
}

bool operator==(int amount, Bigint &in){
    char *s1 = strdup(in.Final_String);
    char *s2 = in.Int2String_Conversion(amount);
    if(strcmp(s1, s2) == 0){
        return true;
    }
    else
        return false;
    return true;
}

//  跟上課投影片一樣，如果等於不成立就代表不等於。
bool Bigint::operator!=(const Bigint &in) const{
    return !(in == *this);
}

bool operator!=(Bigint &in, int amount){
    return !(in == amount);
}

bool operator!=(int amount, Bigint &in){
    return !(amount == in);
}

bool Bigint::operator>(const Bigint &in) const{
    if(strcmp(this->Final_String, in.Final_String) > 0){
        return true;
    }
    //  這個函式是要判斷大於，不是大於等於，如果會走到這一步，代表這兩個字串是
    //  等於或者小於，要回傳false
    return false;
}

bool Bigint::operator<(const Bigint &in) const{
    if(strcmp(this->Final_String, in.Final_String) < 0){
        return true;
    }
    //  這個函式是要判斷小於，不是小於等於，如果會走到這一步，代表這兩個字串是
    //  等於或大於，要回傳false
    return false;
}

//  大於等於，大於或者等於就回傳true
bool Bigint::operator>=(const Bigint &in) const{
    int ret = strcmp(this->Final_String, in.Final_String);
    if(ret > 0 || ret == 0){
        return true;
    }
    return false;
}

//  小於等於，小於或者等於就回傳true
bool Bigint::operator<=(const Bigint &in) const{
    int ret = strcmp(this->Final_String, in.Final_String);
    if(ret < 0 || ret == 0){
        return true;
    }
    return false;
}

//  支援<<來輸出字串，因為我的實作方法的關係，前面可能會有很多零，如果數小於45
//  位數的話前面會有一堆零，所以一開始會先把前面沒有意義的零拿掉，再來下面的if
//  是檢查零，因為如果值是零，我會存45個零，這邊就直接os << '0'。
ostream & operator<<(ostream &os, const Bigint &in){
    int i=0;
    while(in.Final_String[i] == '0'){
        i++;
    }
    if(i == 45){
        os << '0';
    }
    os << &(in.Final_String[i]);
    return os;
}

//  支援>>來輸入資料，*ptr是待會要把輸入資料擺進物件裡面的指標，
istream & operator>>(istream &is, Bigint &in){
    int i=0, len, offset;
    char *line = (char *)malloc(sizeof(char) * 46);
    char *ptr = in.Final_String;
    //  先把物件裡面的字串清乾淨，全部都擺零。
    for(i=0; i<45; i++){
         *(ptr+i) = '0';
    }
    *(ptr+i) = '\0';    //  最後面一定要記得放空字元，不然都會印出一些垃圾字元。
    is >> line;         //  把輸入資料給line
    len = strlen(line); //  拿長度
    *(line+len) = '\0'; //  幫他在最後面放空字元，或許多餘，但是重要。
    offset = 45 - len;  //  offset是代表待會要從哪一個位置開始放input字串，因為前面都會是零。
    i = 0;
    while(*(line+i) != '\0' && i<=len){
        *(ptr+offset+i) = *(line+i);
        ++i;
    }
    *(ptr+offset+i) = '\0'; //  最後面再次擺空字元，很怕忘記。

    return is;
}

