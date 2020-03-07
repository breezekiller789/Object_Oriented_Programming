#include "header.h"

using namespace std;

struct lnode *NewNode(){
    struct lnode *node = (struct lnode *)malloc(sizeof(struct lnode));
    node->cnt = 0;
    node->next = NULL;
    return node;
};

void Insert(struct lnode *head, char ptr){
    struct lnode *node = NULL;
    for(node=head; node->next != NULL; node = node->next){
        if(node->key == ptr){
            node->cnt++;
            break;
        }
    }
    if(node->next == NULL){
        node->next = NewNode();
        node->key = ptr;
        node->cnt++;
    }
    else
        return;
}

void Traverse_List(struct lnode *head){
    struct lnode *node = head;
    while(node->next != NULL){
        printf("%c-%d\n", node->key, node->cnt);
        node = node->next;
    }
}
