#include <iostream>
#include <string.h>
#define MaxLine 1024

struct lnode{
    char key;
    int cnt;
    struct lnode *next;
};
