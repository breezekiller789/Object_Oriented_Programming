#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <limits.h>
#include <iostream>
#define MaxLine 1024

using namespace std;

//  Part A
class Polygon{

private:
    unsigned int _m;
    unsigned int _n;
    double **_point;

public:
    //  Default Constructor
    Polygon(): _m(0), _n(0){
        printf("Default constructor with initial value %d %d\n", this->_m, this->_n);
        fflush(stdout);
    };
    Polygon(unsigned int m, unsigned int n): _m(m), _n(n){
        printf("Default constructor with initial value %d %d\n", this->_m, this->_n);
        //  Allocate _point according to m and n
        this->_point = new double*[this->_m];
        for(int i=0; i<this->_m; i++){
            this->_point[i] = new double[this->_n];
        }
        fflush(stdout);
    };

    //  Copy Constructor
    Polygon(const Polygon &cp){
        cout << "Copy Constructor..." << endl;
        this->_m = cp._m;
        this->_n = cp._n;
        this->_point =  cp._point;
    };
    
    //  Destructor
    ~Polygon(){
        cout << "Destructor..." << endl;
    };


    double* FindCentroid() const; // return the centroid of the polygon
    const int getNumOfPoints() const;
    const int getDimension() const;
    const double getValue (unsigned int m, unsigned int n) const;
    bool setValue (double & value, unsigned int m, unsigned int n);

};

void PrintPoints(Polygon p);


//  Part B
class LinkedList;    // 為了將class LinkedList設成class ListNode的friend,
                     // 需要先宣告
class ListNode{
    private:
        int coef;
        int exp;
        ListNode *next;
    public:
        ListNode():coef(0), exp(0), next(0){};
        ListNode(int c, int e):coef(c), exp(e), next(0){};

        friend class LinkedList;
};

class LinkedList{
    private:
        // int size;                // size是用來記錄Linked list的長度, 非必要
        ListNode *first;            // list的第一個node
    public:
        LinkedList():first(0){
            cout << "Default Constructor" << endl;
            ListNode *NewNode = new ListNode();
            first = NewNode;
        };
        LinkedList(int *c, int *e, int num);
        ~LinkedList(){
            cout << "Destructor..." << endl;
        }
        void PrintList();           // 印出list的所有資料
        void Push_front(int c, int e);     // 在list的開頭新增node
        void Push_back(int c, int e);      // 在list的尾巴新增node
        void Delete(int c, int e);
        void Clear();               // 把整串list刪除
        /* void Reverse();             // 將list反轉: 7->3->14 => 14->3->7 */
        void add(int c, int e);
        void differential();
};
