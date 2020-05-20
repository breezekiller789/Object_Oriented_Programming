#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    Bigint x(999999999, 24123, 111, 33333333, 123456789);
    Bigint y(321000, 5313, 111, 3119033, 123456789);
    Bigint n(000, 000, 000, 000, 000);
    Bigint m(000, 000, 000, 000, 000);
    Bigint a(111111111, 111111111, 111111111, 111111111, 111111111);
    Bigint b(999999999, 999999999, 999999999, 999999999, 999999999);
    Bigint z = m - n;
    cout << z << endl;
    /* cout << x << endl; */
    /* cout << y << endl; */
    /* cout << n << endl; */
    /* cout << z << endl; */
    return 0;
}
