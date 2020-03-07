#include "header.h"

using namespace std;

struct lnode *NewNode();
void Insert(struct lnode *head, char ptr);
void Traverse_List(struct lnode *head);

int main(int argc, char **argv){
    char *line, *ptr;
    int len;
    struct lnode *head = NewNode();
    struct lnode *node = NULL;
    line = (char *)malloc(sizeof(char) * MaxLine);
    while(cin.getline(line, MaxLine)){
        len = strlen(line);
        ptr = line;
        node = head;
        for(int i=0; i<len; i++, ptr++){
            Insert(head, *ptr);
        }
    }
    Traverse_List(head);
    return 0;
}
