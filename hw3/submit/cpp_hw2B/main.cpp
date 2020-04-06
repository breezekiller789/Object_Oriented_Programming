#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    int List_Size=0;
    FILE *fp = fopen("./Input_Files/input4.txt", "r");
    int fd = open("./Input_Files/input4.txt", O_RDONLY);
    int Cnt=0, File_Size = Get_File_Size(fd);
    char *Line = (char *)malloc(sizeof(char) * File_Size);
    char *ptr;
    if(fp == NULL){
        fprintf(stderr, "File Open Failure\n");
        exit(1);
    }

    Parse_Input(fp, Line, Cnt, File_Size);
    ptr = Line;
    /* printf("%s", ptr); */
    /* fflush(stdout); */

    Lnode *Head = NewNode();
    Lnode *node = NULL;
    while(*ptr){
        node = Insert(node, Head, *ptr, List_Size);
        ptr++;
    }
    /* cout << "List Size = " << List_Size << endl; */

    Print_List(Head, List_Size);
    Free_List(Head, List_Size);
    return 0;
}
