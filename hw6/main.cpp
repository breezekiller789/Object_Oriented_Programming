#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    FILE *fp = fopen("sample.in", "r");
    int Num_Students=0, cnt=0;
    fscanf(fp, "%d", &Num_Students);
    /* printf("%d\n", Num_Students); */

    Student **list = new Student *[Num_Students];

    Parser(Num_Students, fp, list);

    //  TODO : 總平均的級分數還沒做, get it done, boy.
    printf("============================\n");
    for(int i=0; i<Num_Students; i++){
        (*(list+i))->info();
        printf("Final Exam = %d\n", (*(list+i))->Get_Final_Exam_Grade());
        printf("Final Average = %.2f", (*(list+i))->Get_Final_Average());
        printf("\n============================\n");
    }


    return 0;
}
