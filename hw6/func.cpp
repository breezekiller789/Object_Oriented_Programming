#include "header.h"

using namespace std;

void Student::init(char *fn, char *ln, char *subject){
    strcpy(this->course, subject);
    strcpy(this->first_name, fn);
    strcpy(this->last_name, ln);
}

void Student::info(){
    if(strcmp(course, "Math") == 0){
        printf("fn = %s\n", this->first_name);
        printf("ln = %s\n", this->last_name);
        printf("course = %s\n", this->course);
    }
    else if(strcmp(course, "English") == 0){
        printf("fn = %s\n", this->first_name);
        printf("ln = %s\n", this->last_name);
        printf("course = %s\n", this->course);
    }
    else if(strcmp(course, "History") == 0){
        printf("fn = %s\n", this->first_name);
        printf("ln = %s\n", this->last_name);
        printf("course = %s\n", this->course);
    }
}

English::English(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<4; i++){
        this->English_Grade[i] = Grades[i];
        /* printf("%d ", this->English_Grade[i]); */
    }
}

Math::Math(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<8; i++){
        this->Math_Grade[i] = Grades[i];
        /* printf("%d ", this->Math_Grade[i]); */
    }
}

History::History(int *Grades, char *fn, char *ln, char *subject){
    init(fn, ln, subject);
    for(int i=0; i<3; i++){
        this->History_Grade[i] = Grades[i];
        /* printf("%d ", this->History_Grade[i]); */
    }
}

int English::Get_Final_Exam_Grade(){
    return this->English_Grade[3];
}

int Math::Get_Final_Exam_Grade(){
    return this->Math_Grade[7];
}

int History::Get_Final_Exam_Grade(){
    return this->History_Grade[2];
}

float English::Get_Final_Average(){
    float Attendance = this->English_Grade[0] * 0.1;
    float Project = this->English_Grade[1] * 0.3;
    float Midterm = this->English_Grade[2] * 0.3;
    float Final_Exam = this->English_Grade[3] * 0.3;
    float result;
    result = Attendance + Project + Midterm + Final_Exam;
    return result;
}

float Math::Get_Final_Average(){
    float result = 0;
    float quiz = 0;
    float Test1 = this->Math_Grade[5] * 0.25;
    float Test2 = this->Math_Grade[6] * 0.25;
    float Final_Exam = this->Math_Grade[7] * 0.35;
    for(int i=0; i<5; i++){
        quiz += (this->Math_Grade[i] * 0.03);
    }
    result = quiz + Test1 + Test2 + Final_Exam;
    return result;
}

float History::Get_Final_Average(){
    float Term_Paper = this->History_Grade[0] * 0.25;
    float Midterm = this->History_Grade[1] * 0.35;
    float Final_Exam = this->History_Grade[2] * 0.4;
    float result;
    result = Term_Paper + Midterm + Final_Exam;
    return result;
}

int rmnewline(char *line){
    char *ptr = line;
    int len=0;
    while(*ptr && *ptr != '\n'){
        ptr++;
        len++;
    }
    *ptr = '\0';
    return len;
}

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
    int cnt=0;
    char *qtr = first_name;
    while(*ptr && *ptr != ','){
        *qtr = *ptr;
        ptr++;
        qtr++;
        cnt++;
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

void Parser(int Num_Students, FILE *fp, Student **list){
    char *line = (char *)malloc(sizeof(char) * MaxLine);
    char *ptr, *qtr;
    char first_name[20];
    char last_name[20];
    char subject[10];
    int English_Grade[4], History_Grade[3], Math_Grade[8];
    int cnt=0;
    while(fgets(line, MaxLine, fp)){
        rmnewline(line);
        ptr = line;
        /* printf("%s\n", line); */
        //  如果一開始就空掉，這行就不要做，不然會有bug。
        if(*ptr == 0)
            continue;

        //  拿成績。
        if(strstr(ptr, "Math") || strstr(ptr, "English") || strstr(ptr, "History")){
            Get_Subject(ptr, subject);
            /* printf("subject = %s\n", subject); */
            //  該項是數學成績。
            if(strstr(ptr, "Math")){
                while(!isspace(*ptr)){
                    ptr++;
                }
                ptr++;

                sscanf(ptr, "%d %d %d %d %d %d %d %d", &Math_Grade[0], &Math_Grade[1],
                        &Math_Grade[2], &Math_Grade[3], &Math_Grade[4], &Math_Grade[5],
                        &Math_Grade[6], &Math_Grade[7]);
                *(list+cnt) = new Math(Math_Grade, first_name, last_name, subject);
                cnt++;
            }
            //  該項是英文成績。
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
            /* printf("\n==========================\n"); */
            continue;
        }

        //  Get First Names
        int shift_amount = Get_First_Names(ptr, first_name);
        /* printf("first name = %s\n", first_name); */

        ptr += shift_amount;

        //  Get Last Names
        Get_Last_Names(ptr, last_name);
        /* printf("last name = %s\n", last_name); */

    }
    /* printf("cnt = %d\n", cnt); */
}


