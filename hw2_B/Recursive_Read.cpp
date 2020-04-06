#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <iostream>
#define MaxLine 1024

using namespace std;

int Get_File_Size(int fd){
    int length = lseek(fd, 0, SEEK_END) + 1;
    return length;
}

char *Print(FILE *fp, char *ptr, int Cnt, int File_Size){
    if(Cnt == File_Size){
        return NULL;
    }
    if(Cnt != File_Size){
        int c = fgetc(fp);
        printf("%c", c);
        fflush(stdout);
        return Print(fp, ptr+1, Cnt+1, File_Size);
    }
    return NULL;
}

void rmnewline(char *Line){
    char *ptr = Line;
    while(*ptr && *ptr != '\n'){
        ptr++;
    }
    *ptr = '\0';
}

int main(int argc, char *argv[]){

    int fd = open("input.txt", O_RDONLY);
    FILE *fp = fopen("input.txt", "r");
    int Cnt=0, File_Size = Get_File_Size(fd);
    char *Line = (char *)malloc(sizeof(char) * File_Size);
    Print(fp, Line, Cnt, File_Size);
    /* while(fgets(Line, File_Size, fp)){ */
    /*     Print(fp, Line, Cnt, File_Size); */
    /* } */


    return 0;
}
