#include "header.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    FILE *fp = fopen("./Input_Files/input3.txt", "r");
    int *Array, List_Size, Max;
    float Avg_Result[3]={0};

    //  Check if open file successfully
    if(fp == NULL){
        fprintf(stderr, "Opening File Error!\n");
        exit(1);
    }

    //  Call ReadList() to Parse inputs and then return the size of list, 
    //  if size is 0, then it must be a invalid input format
    if((List_Size = ReadList(fp, &Array)) == 0){
        fprintf(stderr, "Input Empty!\n");
        exit(2);
    }

    //  Calculate average of integers, positive integers, negative integers
    //  if it's done, it will place the results into Avg_Result[]
    Average(Array, List_Size, Avg_Result);

    //  First of all, call Large() to get the Max integer in the Array, and
    //  then use the return value to call Display() to print out the results
    Display(Avg_Result, Max = Large(Array, List_Size));

    //  Check if Array or fp is null, if any is null, it will be wrong to free
    //  it
    if(Array != NULL && fp != NULL){
        free(Array);
        fclose(fp);
    }
    else{
        fprintf(stderr, "free() Error! Due to Array or fp not NULL\n");
    }

    return 0;
}
