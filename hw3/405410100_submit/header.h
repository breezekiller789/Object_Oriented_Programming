#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>
#include <iomanip>

#define MaxLine 1024

using namespace std;

class Diamond{
private:
    int Diamond_Size;
    char Border;
    char Fill;
public:
    Diamond(int size): Diamond_Size(size){
        if(size < 1){
            Diamond_Size = 1;
        }
        if(size > 39){
            Diamond_Size = 39;
        }
        this->Border = '#';
        this->Fill = '*';
    };
    Diamond(int size, char border):Diamond_Size(size), Border(border), Fill('*'){
        if(size < 1){
            Diamond_Size = 1;
        }
        if(size > 39){
            Diamond_Size = 39;
        }
    };
    Diamond(int size, char border, char fill):Diamond_Size(size), Border(border),
    Fill(fill){
        if(size < 1){
            Diamond_Size = 1;
        }
        if(size > 39){
            Diamond_Size = 39;
        }
    };
    void Draw(void);
    void Shrink(void);
    void Grow(void);
    int GetSize(void);
    int Perimeter(void);
    double Area(void);
    void SetBorder(char key);
    void SetFill(char key);
    void Summary(void);
    char GetBorder(void);
    char GetFill(void);
    void info(void);
};
