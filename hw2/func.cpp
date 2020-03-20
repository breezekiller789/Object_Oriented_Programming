#include "header.h"

using namespace std;

int ReadList(FILE *fp, int **Array){

    *Array = (int *)malloc(sizeof(int) * 100);
    int Cnt=0;
    for(int i=0; fscanf(fp, "%d", *Array+i) != EOF; i++, Cnt++);
    return Cnt;
}

void Average(int *Array, int List_Size, float Avg_Result[3]){
    int Int_Sum=0, Sum_Positive=0, Sum_Negative=0;
    int Positive_Cnt=0, Negative_Cnt=0;
    //  sum all the values, and put it into each specific variable
    for(int i=0; i<List_Size; i++){
        Int_Sum += *(Array+i);
        if(*(Array+i) > 0){
            Sum_Positive += *(Array+i);
            Positive_Cnt++;
        }
        else if(*(Array+i) < 0){
            Sum_Negative += *(Array+i);
            Negative_Cnt++;
        }
        else
            continue;
    }
    //  Check if any count is 0, maybe there are no positive or negative integers
    //  in the list, if 0, put the 0 in the results, or we will end up dividing 0
    //  situation, and that will cause error.
    if(List_Size == 0){
        Avg_Result[0] = 0;
    }
    else{
        Avg_Result[0] = (float)Int_Sum/List_Size;
    }
    if(Positive_Cnt == 0){
        Avg_Result[1] = 0;
    }
    else{
        Avg_Result[1] = (float)Sum_Positive/Positive_Cnt;
    }
    if(Negative_Cnt == 0){
        Avg_Result[2] = 0;
    }
    else{
        Avg_Result[2] = (float)Sum_Negative/Negative_Cnt;
    }
}

//  Find Max
int Large(int *Array, int List_Size){
    
    int Max = *(Array+0);
    for(int i=0; i<List_Size; i++){
        if(*(Array+i) > Max){
            Max = *(Array+i);
        }
    }
    return Max;
}

// Output the results
void Display(float Avg_Result[3], int Max){

    cout << "Integer Avg = " << Avg_Result[0] << endl;
    cout << "Positive Integer Avg = " << Avg_Result[1] << endl;
    cout << "Negative Integer Avg = " << Avg_Result[2] << endl;
    cout << "Max Value = " << Max << endl;
}
