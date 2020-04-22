#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#define MaxLine 1024
typedef struct Lnode{
    char key;
    struct Lnode *next;
}Lnode;

struct Lnode *NewNode();
struct Lnode *Insert(Lnode *node, Lnode *Head, char, int &);
int Get_File_Size(FILE *fp);
char *Recursive_Read_File(FILE *fp, char *ptr, int Cnt, int File_Size);
void rmnewline(char *Line);
void Parse_Input(FILE *fp, char *Line, int Cnt, int File_Size);
void Print_List(Lnode *Head, int List_Size);
void Free_List(Lnode *Head, int List_Size);
