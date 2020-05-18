#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    /* Bigint x(1000, 24123, 111, 33333333, 123456789); */
    /* Bigint y(321000, 5313, 111, 3119033, 123456789); */
    /* Bigint n(0001, 01, 00100001, 00000001, 1); */
    Bigint a(111111111, 111111111, 111111111, 111111111, 111111111);
    Bigint b(888888888, 888888888, 888888888, 888888888, 888888888);
    Bigint z = a + b;
    cout << "==============================\n";
    /* cout << x << endl; */
    /* cout << y << endl; */
    /* cout << n << endl; */
    /* cout << z << endl; */
    return 0;
}
