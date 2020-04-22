#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "r");
    int fd = open("./Input_Files/input5.txt", O_RDONLY);
    int Cnt=0, File_Size, List_Size=0;
    char *Line, *ptr;

    //  Check if file opened successfully
    if(fp == NULL || fd == -1){
        fprintf(stderr, "File Open Failure\n");
        exit(1);
    }

    //  Get file size
    File_Size = Get_File_Size(fp);
    /* printf("File Size = %d\n", File_Size); */

    //  Malloc the size of file
    Line = (char *)malloc(sizeof(char) * File_Size);

    //  Recursively read character after it's done, the Line parameter will be
    //  placed with the input file characters
    Parse_Input(fp, Line, Cnt, File_Size);
    ptr = Line;

    //  Remove new line
    rmnewline(Line);

    Lnode *Head = NewNode();
    Lnode *node = NULL;
    while(*ptr){
        //  Insert one character at a time
        node = Insert(node, Head, *ptr, List_Size);
        ptr++;
    }
    /* cout << "List Size = " << List_Size << endl; */

    //  Print out each node
    Print_List(Head, List_Size);

    //  Free the list
    Free_List(Head, List_Size);

    return 0;
}
