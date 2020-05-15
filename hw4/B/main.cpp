#include "header.h"

using namespace std;

int main() {

    int c[5] = {1, 2, 3, 4, 5};
    int e[5] = {0, 3, 4, 5, 6};
    LinkedList list(c, e, 5);
    list.PrintList();
    list.add(10, 100);
    list.add(30, 5);
    list.PrintList();
    list.differential();
    list.PrintList();

    return 0;
}
