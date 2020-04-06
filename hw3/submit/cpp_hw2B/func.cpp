#include "header.h"

using namespace std;

struct Lnode *NewNode(){
    Lnode *node = (Lnode *)malloc(sizeof(Lnode));
    node->next = NULL;
    return node;
};

struct Lnode *Insert(Lnode *node, Lnode *Head, char c, int &List_Size){
    Lnode *tmp = NewNode();
    if(Head->next == NULL){
        tmp->key = c;
        Head->next = tmp;
        List_Size++;
        return tmp;
    }
    if(c == '\0')
        return NULL;
    //  Insert at tail
    tmp->key = c;
    tmp->next = Head->next;
    node->next = tmp;
    List_Size++;
    return tmp;
}

int Get_File_Size(int fd){
    int length = lseek(fd, 0, SEEK_END)+1;
    return length;
}

char *Recursive_Read_File(FILE *fp, char *ptr, int Cnt, int File_Size){
    if(Cnt == File_Size){
        *ptr = '\0';
        return NULL;
    }
    if(Cnt != File_Size){
        int c = fgetc(fp);
        *ptr = c;
        printf("cnt = %d file_size = %d\n", Cnt, File_Size);
        /* printf("%c", c); */
        fflush(stdout);
        return Recursive_Read_File(fp, ptr+1, Cnt+1, File_Size);
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

void Parse_Input(FILE *fp, char *Line, int Cnt, int File_Size){
    Recursive_Read_File(fp, Line, Cnt, File_Size);
    /* char *ptr = Line; */
    /* for(int i=0; i<File_Size; i++, ptr++){ */
    /*     printf("%c", *ptr); */
    /*     fflush(stdout); */
    /* } */
}

void Print_List(Lnode *Head, int List_Size){
    Lnode *node = Head->next;
    for(int i=0; i<List_Size; node = node->next, i++){
        if(node->key == '\0')
            return;
        cout << node->key;
        fflush(stdout);
    }
}

void Free_List(Lnode *Head, int List_Size){
    Lnode *tmp, *node = Head;
    int cnt = 0;
    while(node->next != NULL && cnt != List_Size){
        tmp = node;
        node = node->next;
        free(tmp);
        cnt++;
    }
}
