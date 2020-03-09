#include "header.h"

using namespace std;

//  Return a allocated memory
struct lnode *NewNode(){
    struct lnode *node = (struct lnode *)malloc(sizeof(struct lnode));
    node->cnt = 0;
    node->next = NULL;
    return node;
};

void Insert(struct lnode *head, char ptr){
    struct lnode *node = NULL;
    //  Go through the whole list to see if the character has already existed
    //  if exists, plus the count by 1 the break.
    for(node=head; node->next != NULL; node = node->next){
        if(node->key == ptr){
            node->cnt++;
            break;
        }
    }

    //  If node->next equals to NULL, then it means the whole list doesn't
    //  exist target character, so call NewNode() to get a new node, and insert
    //  it.
    if(node->next == NULL){
        node->next = NewNode();
        node->key = ptr;
        node->cnt++;
    }
    //  Or return the function
    else
        return;
}

//  Print out all the characters and the counts
void Traverse_List(struct lnode *head){
    struct lnode *node = head;
    while(node->next != NULL){
        printf("%c-%d\n", node->key, node->cnt);
        node = node->next;
    }
}
