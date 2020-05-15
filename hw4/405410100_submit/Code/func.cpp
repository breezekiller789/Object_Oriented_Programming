#include "header.h"

using namespace std;

//  Part A
//  算重心
double *Polygon::FindCentroid() const{
    double *c = new double[this->_n];
    for(int i=0; i<(this->_n); i++){
        double sum = 0;
        for(int j=0; j<(this->_m); j++){
            sum += _point[j][i];
        }
        /* cout << sum << endl; */
        c[i] = sum / this->_m;
    }
    return c;
};

const int Polygon::getNumOfPoints() const{
    return this->_m;
}

const int Polygon::getDimension() const {
    return this->_n;
}

// Accessor: Get the value stored at the m-th point and n-th
// dimension
const double Polygon::getValue (unsigned int m, unsigned int n) const {
    if (m<0 || m>=_m || n<0 || n>=_n) {
        cerr << "ERROR: Index our of range" << endl;
        exit(-1);
    }
    else 
        return _point[m][n];
}

// Mutator: Set the value at the m-th point and n-th coordinate
bool Polygon::setValue (double & value, unsigned int m, unsigned int n) {
    if (m>=0 && m<_m && n>=0 && n<_n) {
        _point[m][n] = value;
        return true;
    }
    else
        return false;
}

void PrintPoints (Polygon p) {
    for(unsigned int i=0; i<p.getNumOfPoints(); i++){
        for(unsigned int j=0; j<p.getDimension(); j++){
            cout << p.getValue(i, j) << " " ;
        }
        cout << endl;
    }
}


//  Part B
LinkedList::LinkedList(int *c, int *e, int num){
    ListNode *NewNode = new ListNode();
    first = NewNode;
    cout << "Default Constructor with value..." << endl;
    for(int i=0; i<num; i++){
        this->add(c[i], e[i]);
    }
}

void LinkedList::add(int c, int e){
    this->Push_back(c, e);
}

//  微分，指數乘以係數，之後指數減一
void LinkedList::differential(){
    ListNode *current = first->next;
    while(current != 0){
        current->coef *= current->exp;
        current->exp--;
        current = current->next;
    }
}

//  印出list
void LinkedList::PrintList(){

    if (first->next == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = first->next;             // 用pointer *current在list中移動
    while (current != 0) {                      // Traversal
        //  如果指數項為零且係數不為零，直接印係數，比較好看也比較直觀。
        if(current->exp == 0 && current->coef != 0){
            cout << current->coef;
        }
        //  係數為零，都不要印，直接return
        else if(current->coef == 0){
            current = current->next;
            continue;
        }
        else
            cout << current->coef << "X^" << current->exp;

        if(current->next != 0){
            cout << " + ";
        }
        current = current->next;
    }
    cout << endl;
}


//  insert at front
void LinkedList::Push_front(int c, int e){

    ListNode *newNode = new ListNode(c, e);   // 配置新的記憶體
    newNode->next = first->next;                 // 先把first->next接在newNode後面
    first->next = newNode;                       // 再把first->next指向newNode所指向的記憶體位置
}

//  insert at tail
void LinkedList::Push_back(int c, int e){

    ListNode *newNode = new ListNode(c, e);   // 配置新的記憶體

    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0) {           // Traversal
        if(current->exp == e){
            current->coef += c;
            return;
        }
        current = current->next;
    }
    current->next = newNode;               // 將newNode接在list的尾巴
}


void LinkedList::Delete(int c, int e){

    ListNode *current = first,      
             *previous = 0;
    while (current != 0 && current->coef != c && current->exp != e) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->next;                  // 或是current->data == x
    }                                             // 即結束while loop

    if (current == 0) {                 // list沒有要刪的node, 或是list為empty
        std::cout << "There is no " << c << "+" << e << " in list.\n";
        // return;
    }
    else if (current == first) {        // 要刪除的node剛好在list的開頭
    	first = current->next;          // 把first移到下一個node
        delete current;                 // 如果list只有一個node, 那麼first就會指向NULL
        current = 0;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
        // return;                     
    }
    else {                              // 其餘情況, list中有欲刪除的node, 
        previous->next = current->next; // 而且node不為first, 此時previous不為NULL
        delete current;
        current = 0;
        // return;
    }
}


void LinkedList::Clear(){

    while (first->next != 0) {            // Traversal
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}


//  有bug，當反過來之後，原本的第一個會不見...
/* void LinkedList::Reverse(){ */

/*     if (first == 0 || first->next == 0) { */
/*         // list is empty or list has only one node */
/*         return; */
/*     } */

/*     ListNode *previous = 0, */
/*              *current = first, */
/*              *preceding = first->next; */

/*     while (preceding != 0) { */
/*         current->next = previous;      // 把current->next轉向 */
/*         previous = current;            // previous往後挪 */
/*         current = preceding;           // current往後挪 */
/*         preceding = preceding->next;   // preceding往後挪 */
/*     }                                  // preceding更新成NULL即跳出while loop */

/*     current->next = previous;          // 此時current位於最後一個node, 將current->next轉向 */
/*     first = current;                   // 更新first為current */
/* } */
