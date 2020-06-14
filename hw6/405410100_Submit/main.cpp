#include "header.h"

using namespace std;

int main(int argc, char *argv[]){
    if(argc != 3){
        usage();
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    FILE *Output_fp = fopen(argv[2], "w");
    int Num_Students=0;
    char Courses[3][10] = {"English", "History", "Math"};

    //  第一行代表有幾個學生的資料。
    fscanf(fp, "%d", &Num_Students);

    Student **list = new Student *[Num_Students];

    //  把Input做Parsing
    Parser(Num_Students, fp, list);

    //  把結果印到Output_fp裡面。
    Export_Result_File(Output_fp, list, Num_Students, Courses);

    return 0;
}
