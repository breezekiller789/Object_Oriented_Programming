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

int Get_File_Size(FILE *op){
    int size;
    fseek(op, 0, SEEK_END);
    size = ftell(op);
    return size;
}

int main(int argc, char *argv[]){

    FILE *fp = fopen("hw3.grade", "r");
    FILE *op = fopen("./output.txt", "w+");
    char *line = (char *)malloc(sizeof(char) * MaxLine);
    char *ptr;
    int cnt=0, grade, sum=0;
    while(fgets(line, MaxLine, stdin) != NULL){
        rmnewline(line);
        ptr = line;
        fprintf(op, "%s ", ptr);
    }
    rewind(op);
    int size = Get_File_Size(op);
    char *word = (char *)malloc(sizeof(char) * size + 10);
    rewind(op);
    while(fgets(word, size, op) != NULL){
        ptr = word;
        char *tmp;
        while((ptr = strstr(ptr, "40")) != NULL){
            int haha=0;
            tmp = ptr;
            while(isdigit(*tmp)){
                tmp++;
                haha++;
            }
            if(haha < 9){
                ptr += haha;
                continue;
            }

            if(*(ptr+2) >= '5' && *(ptr+2) <= '7'){
                cnt++;
                while(isdigit(*ptr)){
                    printf("%c", *ptr);
                    ptr++;
                }
                printf("\t");
                ptr++;
                int num = atoi(ptr);
                sum += num;
                printf("%d\n", num);
            }
            else{
                while(isdigit(*ptr)){
                    ptr++;
                    continue;
                }
            }
        }
    }
    printf("sum = %d\n", sum);
    printf("cnt = %d\n", cnt);
    printf("avg = %f\n", (float)(sum/cnt));
    remove("output.txt");

    return 0;
}
