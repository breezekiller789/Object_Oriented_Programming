#include <iostream>
#include <string.h>
#define MaxLine 1024

struct lnode *NewNode();
void Insert(struct lnode *head, char ptr);
void Traverse_List(struct lnode *head);

struct lnode{
    char key;
    int cnt;
    struct lnode *next;
};
