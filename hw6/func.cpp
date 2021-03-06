#include "header.h"

using namespace std;

//  把學生的基本資料做初始化。
void Student::init(char *fn, char *ln, char *subject){
    strcpy(this->course, subject);
    strcpy(this->first_name, fn);
    strcpy(this->last_name, ln);
}

//  印出學生的姓名。
void Student::info(FILE *Output_fp){
    if(strcmp(course, "Math") == 0){
        fprintf(Output_fp, "%s %s\t\t", this->last_name, this->first_name);
    }
    else if(strcmp(course, "English") == 0){
        fprintf(Output_fp, "%s %s\t\t", this->last_name, this->first_name);
    }
    else if(strcmp(course, "History") == 0){
        fprintf(Output_fp, "%s %s\t\t", this->last_name, this->first_name);
    }
}

char *Student::Get_Course(){
    return this->course;
}

English::English(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<4; i++){
        this->English_Grade[i] = Grades[i];
    }
}

Math::Math(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<8; i++){
        this->Math_Grade[i] = Grades[i];
    }
}

History::History(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<3; i++){
        this->History_Grade[i] = Grades[i];
    }
}

//  回傳該學生的英文期末考成績
int English::Get_Final_Exam_Grade(){
    return this->English_Grade[3];
}

//  回傳該學生的數學期末考成績
int Math::Get_Final_Exam_Grade(){
    return this->Math_Grade[7];
}

//  回傳該學生的歷史期末考成績
int History::Get_Final_Exam_Grade(){
    return this->History_Grade[2];
}

//  回傳該學生這個學期英文的期末平均分數。
float English::Get_Final_Average(){
    //  Attendance 10%
    //  Project 30%
    //  Midterm 30%
    //  Final Exam 30%
    float Attendance = this->English_Grade[0] * 0.1;
    float Project = this->English_Grade[1] * 0.3;
    float Midterm = this->English_Grade[2] * 0.3;
    float Final_Exam = this->English_Grade[3] * 0.3;
    float result;
    result = Attendance + Project + Midterm + Final_Exam;
    return result;
}

//  回傳該學生這個學期數學的期末平均分數。
float Math::Get_Final_Average(){
    //  5 quiz, 3% each, total 15%
    //  Test1 25%
    //  Test2 25%
    //  Final Exam 35%
    float result = 0;
    float quiz = 0;
    float Test1 = this->Math_Grade[5] * 0.25;
    float Test2 = this->Math_Grade[6] * 0.25;
    float Final_Exam = this->Math_Grade[7] * 0.35;
    //  把小考成績做加權平均，我這邊是每一次都乘以0.03，其實也可以把全部都加起
    //  來之後再乘以15%，但我選擇分開算，對我來講比較直覺。
    for(int i=0; i<5; i++){
        quiz += (this->Math_Grade[i] * 0.03);
    }
    result = quiz + Test1 + Test2 + Final_Exam;
    return result;
}

//  回傳該學生這個學期歷史的期末平均分數。
float History::Get_Final_Average(){
    //  Term Paper 25%
    //  Midterm 35%
    //  Final Exam 40%
    float Term_Paper = this->History_Grade[0] * 0.25;
    float Midterm = this->History_Grade[1] * 0.35;
    float Final_Exam = this->History_Grade[2] * 0.4;
    float result;
    result = Term_Paper + Midterm + Final_Exam;
    return result;
}

//  100-90  A
//  89-80   B
//  79-70   C
//  69-60   D
//  59-0    F
//  數學的Letter Grade
char English::Get_Letter_Grade(){
    float Final_Avg = this->Get_Final_Average();
    //  可能會超過一百分，超過一百一樣是A
    if(Final_Avg > 100)
        return 'A';
    if(Final_Avg >= 90 && Final_Avg < 100){
        return 'A';
    }
    else if(Final_Avg >= 80 && Final_Avg < 90){
        return 'B';
    }
    else if(Final_Avg >= 70 && Final_Avg < 80){
        return 'C';
    }
    else if(Final_Avg >= 60 && Final_Avg < 70){
        return 'D';
    }
    else{
        return 'F';
    }
    return 'F';
}

//  數學的Letter Grade
char Math::Get_Letter_Grade(){
    float Final_Avg = this->Get_Final_Average();
    //  可能會超過一百分，超過一百一樣是A
    if(Final_Avg > 100)
        return 'A';
    if(Final_Avg >= 90 && Final_Avg < 100){
        return 'A';
    }
    else if(Final_Avg >= 80 && Final_Avg < 90){
        return 'B';
    }
    else if(Final_Avg >= 70 && Final_Avg < 80){
        return 'C';
    }
    else if(Final_Avg >= 60 && Final_Avg < 70){
        return 'D';
    }
    else{
        return 'F';
    }
    return 'F';
}

//  歷史的Letter Grade
char History::Get_Letter_Grade(){
    float Final_Avg = this->Get_Final_Average();
    //  可能會超過一百分，超過一百一樣是A
    if(Final_Avg > 100)
        return 'A';
    if(Final_Avg >= 90 && Final_Avg < 100){
        return 'A';
    }
    else if(Final_Avg >= 80 && Final_Avg < 90){
        return 'B';
    }
    else if(Final_Avg >= 70 && Final_Avg < 80){
        return 'C';
    }
    else if(Final_Avg >= 60 && Final_Avg < 70){
        return 'D';
    }
    else{
        return 'F';
    }
    return 'F';
}

//  把讀進來的這行去掉換行符號
int rmnewline(char *line){
    char *ptr = line;
    int len=0;
    while(*ptr && *ptr != '\n'){
        ptr++;
        len++;
    }
    *ptr = '\0';    //  最後記得要放空字元。
    return len;
}

//  Get Subject，把科目的字串放進subject裡面
void Get_Subject(const char *ptr, char *subject){
    char *qtr = subject;
    while(*ptr && !isspace(*ptr)){
        *qtr = *ptr;
        ptr++;
        qtr++;
    }
    *qtr = 0;
}

//  Get First Name
int Get_First_Names(const char *ptr, char *first_name){
    int cnt=0;  //  cnt是待會我要回傳回去的，代表First Name有多長，我待會回去之後就跳過這個長度。
    char *qtr = first_name;
    int len = strlen(ptr);
    int offset = 20-len;
    //  在遇到逗號之前都叫做First name
    while(*ptr && *ptr != ','){
        *qtr = *ptr;
        ptr++;
        qtr++;
        cnt++;
    }
    //  這個for是我後來才加的，因為要為了排版上的方便，我名字全部都給他塞好塞滿
    //  ，就算名字不到20，我也把他用空格塞到20個字元。
    for(int i=0; i<offset; i++, qtr++){
        *qtr = ' ';
    }
    *qtr = 0;

    //  skip all the spaces and coma
    while(*ptr == ',' || isspace(*ptr)){
        ptr++;
        cnt++;
    }
    return cnt;
}

//  Get Last Name
void Get_Last_Names(const char *ptr, char *last_name){
    char *qtr = last_name;
    while(*ptr){
        *qtr = *ptr;
        ptr++;
        qtr++;
    }
    *qtr = 0;
}

//  Parse Input然後把資料都個別讀進來，這個function基本上就是用C來實作，因為有
//  需要用到字串的處理，所以寫起來就是C code
void Parser(int Num_Students, FILE *fp, Student **list){
    char *line = (char *)malloc(sizeof(char) * MaxLine);
    char *ptr, *qtr;
    char first_name[20];
    char last_name[20];
    char subject[10];
    int English_Grade[4], History_Grade[3], Math_Grade[8];
    int cnt=0;
    //  一次讀一行進來。
    while(fgets(line, MaxLine, fp) != NULL){
        //  以前養成的習慣，讀一行進來，要記得把換行拿掉，然後回傳這個字串的長
        //  度，就先存起來。
        int len = rmnewline(line);

        //  如果一開始就空掉，這行就不要做，不然會有bug。
        if(len == 0){
            continue;
        }
        ptr = line;

        //  拿成績，看這一行是不是要輸入學生的科目成績，用strstr()來幫下去找看
        //  看，是不是有存在Math, English, History，有的話就代表這一行是要輸入
        //  成績的。
        if(strstr(ptr, "Math") || strstr(ptr, "English") || strstr(ptr, "History")){
            Get_Subject(ptr, subject);
            //  該項是數學成績。
            if(strstr(ptr, "Math")){
                //  這個while是做防呆，如果Math前面有一堆空格，要略過，不然我後
                //  面在做字串處理會出問題。
                while(!isspace(*ptr)){
                    ptr++;
                }
                ptr++;

                //  到這邊的時候ptr就會剛剛好指到成績的位置。
                sscanf(ptr, "%d %d %d %d %d %d %d %d", &Math_Grade[0], &Math_Grade[1],
                        &Math_Grade[2], &Math_Grade[3], &Math_Grade[4], &Math_Grade[5],
                        &Math_Grade[6], &Math_Grade[7]);
                *(list+cnt) = new Math(Math_Grade, first_name, last_name, subject);
                cnt++;
            }
            //  該項是英文成績，讀資料方法和上面一樣，只是規格稍有不同，基本上
            //  就是依樣畫葫蘆
            else if(strstr(ptr, "English")){
                while(!isspace(*ptr)){
                    ptr++;
                }
                ptr++;

                sscanf(ptr, "%d %d %d %d", &English_Grade[0], &English_Grade[1],
                        &English_Grade[2], &English_Grade[3]);
                *(list+cnt) = new English(English_Grade, first_name, last_name, subject);
                cnt++;
            }
            //  該項是歷史成績。
            else if(strstr(ptr, "History")){
                while(!isspace(*ptr)){
                    ptr++;
                }
                ptr++;

                sscanf(ptr, "%d %d %d", &History_Grade[0], &History_Grade[1],
                        &History_Grade[2]);
                *(list+cnt) = new History(History_Grade, first_name, last_name, subject);
                cnt++;
            }
            continue;
        }

        //  Get First Names，會回傳First_Name的長度，待會就把ptr往前跳。
        int shift_amount = Get_First_Names(ptr, first_name);

        //  跳過去First Name的長度。
        ptr += shift_amount;

        //  Get Last Names
        Get_Last_Names(ptr, last_name);

    }
}

//  把學生的姓名，分數都印出來，參數的course代表我現在要印哪一個科目，數學就先
//  全部都印數學，其他先不用印，從list全部走一次就可以了。
void Print_Result(FILE *Output_fp, Student **list, int Num_Students, const char *course){
    //  把傳進來的科目字串存起來，因為傳進來const，我就用stdup來copy一份。 
    char *ptr = strdup(course);
    for(int i=0; i<Num_Students; i++){
        if(strcmp((*(list+i))->Get_Course(), ptr) == 0){
            (*(list+i))->info(Output_fp);
            fprintf(Output_fp, "%d\t\t  ", (*(list+i))->Get_Final_Exam_Grade());
            fprintf(Output_fp, "%.2f\t\t\t", (*(list+i))->Get_Final_Average());
            fprintf(Output_fp, "%c\n", (*(list+i))->Get_Letter_Grade());
        }
    }

    fprintf(Output_fp, "\n");
}

//  把結果都印到檔案Output.txt裡面，我是用fprintf來印，簡單又方便。
void Export_Result_File(FILE *Output_fp, Student **list, int Num_Students,
        char Courses[3][10]){
    fprintf(Output_fp, "Student Grade Summary\n");
    fprintf(Output_fp, "---------------------\n\n");

    fprintf(Output_fp, "~~~~~~~~~~~~~\n"); 
    fprintf(Output_fp, "ENGLISH CLASS|\n");
    fprintf(Output_fp, "~~~~~~~~~~~~~\n\n"); 
    fprintf(Output_fp, "Student Name\t\tFinal Exam\tFinal Avg\tLetter Grade\n");
    fprintf(Output_fp, "--------------------------------------------------------\n");

    //  輸出英文課的所有同學姓名、成績。
    Print_Result(Output_fp, list, Num_Students, Courses[0]);

    fprintf(Output_fp, "~~~~~~~~~~~~~\n"); 
    fprintf(Output_fp, "HISTORY CLASS|\n" );
    fprintf(Output_fp, "~~~~~~~~~~~~~\n\n"); 
    fprintf(Output_fp, "Student Name\t\tFinal Exam\tFinal Avg\tLetter Grade\n");
    fprintf(Output_fp, "--------------------------------------------------------\n");

    //  輸出歷史課的所有同學姓名、成績。
    Print_Result(Output_fp, list, Num_Students, Courses[1]);

    fprintf(Output_fp, "~~~~~~~~~~\n"); 
    fprintf(Output_fp, "MATH CLASS|\n");
    fprintf(Output_fp, "~~~~~~~~~~\n\n"); 
    fprintf(Output_fp, "Student Name\t\tFinal Exam\tFinal Avg\tLetter Grade\n");
    fprintf(Output_fp, "--------------------------------------------------------\n");

    //  輸出數學課的所有同學姓名、成績。
    Print_Result(Output_fp, list, Num_Students, Courses[2]);
}
