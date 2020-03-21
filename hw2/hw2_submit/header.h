#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <iostream>
#define MaxLine 1024
#define SUCCESS 1
#define FAILED -1

int ReadList(FILE *, int **);
void Average(int *Array, int List_Size, float Avg_Result[3]);
int Large(int *Array, int List_Size);
void Display(float Avg_Result[3], int Max);
