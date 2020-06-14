#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    FILE *fp = fopen("sample.in", "r");
    FILE *Output_fp = fopen("Output.txt", "w");
    /* FILE *fp = fopen("input2.txt", "r"); */
    int Num_Students=0, cnt=0;
    char Courses[3][10] = {"English", "History", "Math"};
    fscanf(fp, "%d", &Num_Students);
    /* printf("%d\n", Num_Students); */

    Student **list = new Student *[Num_Students];

    Parser(Num_Students, fp, list);

    //  把結果印到Output_fp裡面。
    Export_Result_File(Output_fp, list, Num_Students, Courses);

    return 0;
}
