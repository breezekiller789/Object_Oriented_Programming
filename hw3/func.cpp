#include "header.h"

using namespace std;

void Diamond::Draw(void){
    int space = this->Diamond_Size - 1;  
    int n = this->Diamond_Size;
  
    // run loop (parent loop)  
    // till number of rows  
    for (int i = 0; i < n; i++)  
    {  
        // loop for initially space,  
        // before star printing  
        for (int j = 0;j < space; j++)  
            cout << " ";  
  
        // print i+1 stars  
        for (int j = 0; j <= i; j++){
            if(j==0){
                cout << this->Border << " ";
            }
            else if(j==i){
                cout << this->Border << " ";
            }
            else{
                cout << this->Fill << " ";
            }
        }
  
        cout << endl;  
        space--;  
    }  
  
    // repeat again in reverse order  
    space = 1;  
  
    // run loop (parent loop)  
    // till number of rows  
    for (int i = n-1; i > 0; i--)  
    {  
        // loop for initially space,  
        // before star printing  
        for (int j = 0; j < space; j++)  
            cout << " ";  
  
        // print i stars  
        for (int j = 0;j < i;j++){
            if(j==0){
                cout << this->Border << " ";
            }
            else if(j==i-1){
                cout << this->Border << " ";
            }
            else{
                cout << this->Fill << " ";
            }
        }
  
        cout << endl; 
        space++;  
    }  
}

void Diamond::Shrink(void){
    int cnt = this->Diamond_Size;
    if(cnt-1 > 39){
        this->Diamond_Size = 39;
    }
    else if(cnt-1 < 1){
        this->Diamond_Size = 1;
    }
    else{
        this->Diamond_Size -= 1;
    }
}

void Diamond::Grow(void){
    int cnt = this->Diamond_Size;
    if(cnt+1 > 39){
        this->Diamond_Size = 39;
    }
    else if(cnt+1 < 1){
        this->Diamond_Size = 1;
    }
    else{
        this->Diamond_Size += 1;
    }
}

int Diamond::GetSize(void){
    return this->Diamond_Size;
}

int Diamond::Perimeter(void){
    int perimeter;
    int area_long = this->Diamond_Size;
    int area_short = this->Diamond_Size - 2;
    area_long *= area_long;
    area_short *= area_short;
    return area_long - area_short + 4;
}

double Diamond::Area(void){
    int side_length = this->Diamond_Size;
    double area = pow(3, 0.5)/4 * pow(side_length, 2) * 2;
    return area;
}

void Diamond::SetBorder(char key){
    int c = key;
    if(c>=33 && c<=126){
        this->Border = key;
    }
    else{
        this->Border = '#';
    }
}

void Diamond::SetFill(char key){
    int c = key;
    if(c>=33 && c<=126){
        this->Fill = key;
    }
    else{
        this->Fill = '*';
    }
}

void Diamond::Summary(void){
    cout << "Size of diamond's side = " << this->Diamond_Size << " units." << endl;
    cout << "Perimeter of diamond = " << this->Perimeter() << " units." << endl;
    cout << "Area of diamond = " << this->Area() << " units." << endl;
    cout << "Diamond looks like:" << endl;
    this->Draw();
}

void Diamond::info(void){
    cout << "==========" << endl;
    cout << "Size = " << this->Diamond_Size << endl;
    cout << "Border = " << this->Border << endl;
    cout << "Fill = " << this->Fill << endl;
    cout << "Perimeter = " << this->Perimeter() << endl;
    cout << "Area = " << this->Area() << endl;
}

char Diamond::GetBorder(void){
    return this->Border;
}

char Diamond::GetFill(void){
    return this->Fill;
}
