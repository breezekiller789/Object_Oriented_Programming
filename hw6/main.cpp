#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    FILE *fp = fopen("sample.in", "r");
    int Num_Students=0, cnt=0;
    fscanf(fp, "%d", &Num_Students);
    printf("%d\n", Num_Students);

    Student **list = new Student *[Num_Students];

    Parser(Num_Students, fp, list);


    printf("\n\n");

    for(int i=0; i<Num_Students; i++){
        printf("============================\n");
        (*(list+i))->info();
    }


    return 0;
}
