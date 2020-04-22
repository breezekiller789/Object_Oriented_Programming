// C++ program to print diamond shape 
// with 2n rows  
#include <iostream> 
using namespace std; 
  
// Prints diamond pattern with 2n rows  
void printDiamond(int n)  
{  
    int space = n - 1;  
  
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
                cout << "^ ";  
            }
            else if(j==i){
                cout << "^ ";  
            }
            else{
                cout << "@ ";
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
                cout << "^ ";  
            }
            else if(j==i-1){
                cout << "^ ";  
            }
            else{
                cout << "@ ";
            }
        }
  
        cout << endl; 
        space++;  
    }  
}  
  
// Driver code  
int main()  
{  
    printDiamond(7);  
    return 0;  
}  
