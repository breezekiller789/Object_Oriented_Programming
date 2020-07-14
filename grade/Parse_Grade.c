#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#define MaxLine 1024

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

void calculate_interval(int grade, int intervals[10]){
    if(grade>=0 && grade<10){
        intervals[0]++;
    }
    else if(grade>=10 && grade<20){
        intervals[1]++;
    }
    else if(grade>=20 && grade<30){
        intervals[2]++;
    }
    else if(grade>=30 && grade<40){
        intervals[3]++;
    }
    else if(grade>=40 && grade<50){
        intervals[4]++;
    }
    else if(grade>=50 && grade<60){
        intervals[5]++;
    }
    else if(grade>=60 && grade<70){
        intervals[6]++;
    }
    else if(grade>=70 && grade<80){
        intervals[7]++;
    }
    else if(grade>=80 && grade<90){
        intervals[8]++;
    }
    else if(grade>=90 && grade<100){
        intervals[9]++;
    }
}

void show_interval(int intervals[10]){
    printf("99-90   %d\n", intervals[9]);
    printf("89-80   %d\n", intervals[8]);
    printf("79-70   %d\n", intervals[7]);
    printf("69-60   %d\n", intervals[6]);
    printf("59-50   %d\n", intervals[5]);
    printf("49-40   %d\n", intervals[4]);
    printf("39-30   %d\n", intervals[3]);
    printf("29-20   %d\n", intervals[2]);
    printf("19-10   %d\n", intervals[1]);
    printf("9-0     %d\n", intervals[0]);
}

int mycompare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[]){

    char *line = (char *)malloc(sizeof(char) * MaxLine);
    char *ptr;
    int cnt=0, grade, sum=0, intervals[10]={0}, siaowei_grade = 0;
    int all_grade[70] = {0};
    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        if(*ptr == '(' || !isdigit(*ptr)){
            continue;
        }
        if(strncmp(ptr, "40", 2) != 0){
            continue;
        }
        while(isdigit(*ptr)){
            /* printf("%c", *ptr); */
            ptr++;
        }
        /* printf("\t"); */
        grade = atoi(ptr);
        if(strstr(line, "405410100")){
            siaowei_grade = grade;
        }
        all_grade[cnt] = grade;
        calculate_interval(grade, intervals);
        /* printf("%d\n", all_grade[cnt]); */
        sum += grade;
        cnt++;
    }
    printf("sum = %d\n", sum);
    printf("student cnt = %d\n", cnt);
    printf("avg = %f\n", (float)(sum/cnt));

    show_interval(intervals);
    qsort(all_grade, 70, sizeof(int), mycompare);
    //  印出排名位置。
    int avg = (int)(sum/cnt);
    printf("小威的分數 = %d\n", siaowei_grade);
    for(int i=cnt; i>=0; i--){
        /* printf("%d\n", all_grade[i]); */
        if(all_grade[i] == siaowei_grade){
            printf("小威的排名%d\n", cnt-i);
            break;
        }
        /* if(all_grade[i] == avg){ */
        /*     printf("number = %d\n", 109-i); */
        /* } */
    }

    return 0;
}
