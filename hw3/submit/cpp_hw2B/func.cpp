#include "header.h"

using namespace std;

//  Malloc a node and return it
struct Lnode *NewNode(){
    Lnode *node = (Lnode *)malloc(sizeof(Lnode));
    node->next = NULL;
    return node;
};

//  Do circular linked list insertion(insert at tail)
struct Lnode *Insert(Lnode *node, Lnode *Head, char c, int &List_Size){
    Lnode *tmp = NewNode();
    //  Initilal condition, Head->next must be NULL
    if(Head->next == NULL){
        tmp->key = c;
        Head->next = tmp;
        List_Size++;
        return tmp;
    }

    //  I found a bug due to '\0', so i add this line to prevent it from happening
    if(c == '\0')
        return NULL;

    //  Insert at tail
    tmp->key = c;           //  Insert!
    tmp->next = Head->next; //  Point back to the first node(circular linked list)
    node->next = tmp;       //  connect it together
    List_Size++;
    return tmp;
}

//  Use lseek() to get file size
int Get_File_Size(int fd){
    int length = lseek(fd, 0, SEEK_END)+1;  //  0 means start of file, plus one
    return length;                          //  is for '\0'
}

//  Read file recursively
char *Recursive_Read_File(FILE *fp, char *ptr, int Cnt, int File_Size){
    //  lower bound of recursion
    if(Cnt == File_Size){
        *ptr = '\0';
        return NULL;
    }
    if(Cnt != File_Size){
        int c = fgetc(fp);
        *ptr = c;
        /* printf("cnt = %d file_size = %d\n", Cnt, File_Size); */
        /* printf("%c", c); */
        /* fflush(stdout); */
        return Recursive_Read_File(fp, ptr+1, Cnt+1, File_Size);
    }
    return NULL;
}

//  remove newline
void rmnewline(char *Line){
    char *ptr = Line;
    //  scan until the end and place it with '\0'
    while(*ptr && *ptr != '\n'){
        ptr++;
    }
    *ptr = '\0';
}

void Parse_Input(FILE *fp, char *Line, int Cnt, int File_Size){
    Recursive_Read_File(fp, Line, Cnt, File_Size);
}

void Print_List(Lnode *Head, int List_Size){
    Lnode *node = Head->next;
    //  this for loop scan through the whole list
    for(int i=0; i<List_Size; node = node->next, i++){
        if(node->key == '\0'){
            cout << endl;
            return;
        }
        cout << node->key;
        fflush(stdout);
    }
}

void Free_List(Lnode *Head, int List_Size){
    Lnode *tmp, *node = Head;
    int cnt = 0;
    //  i added cnt to prevent it from going out of boundary
    while(node->next != NULL && cnt != List_Size){
        tmp = node;
        node = node->next;
        free(tmp);
        cnt++;
    }
}
