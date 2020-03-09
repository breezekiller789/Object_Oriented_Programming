//  type $make
//       $./hw1 "string"
//  The program will print out all the characters apeared in the string
#include "header.h"

using namespace std;

int main(int argc, char **argv){
    char *ptr;
    int len;
    struct lnode *head = NewNode();

    //  The upperbound is argc, treat each argument as a string, and Insert every
    //  character one by one
    for(int i=1; i<argc; i++){
        len = strlen(argv[i]);
        ptr = strdup(argv[i]);
        //  Do insert
        for(int i=0; i<len; i++, ptr++){
            Insert(head, *ptr);
        }
    }
    //  Print out the answers
    Traverse_List(head);
    return 0;
}
