#include "header.h"

using namespace std;

LinkedList::LinkedList(int *c, int *e, int num){
    for(int i=0; i<num; i++){
        this->add(c[i], e[i]);
    }
}

void LinkedList::add(int c, int e){
    this->Push_back(c, e);
}

void LinkedList::differential(){
    ListNode *current = first->next;
    while(current != 0){
        current->coef *= current->exp;
        current->exp--;
        current = current->next;
    }
}

void LinkedList::PrintList(){

    if (first->next == 0) {                      // 如果first node指向NULL, 表示list沒有資料
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = first->next;             // 用pointer *current在list中移動
    while (current != 0) {                      // Traversal
        if(current->exp == 0){
            cout << current->coef;
        }
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


void LinkedList::Push_front(int c, int e){

    ListNode *newNode = new ListNode(c, e);   // 配置新的記憶體
    newNode->next = first;                 // 先把first接在newNode後面
    first = newNode;                       // 再把first指向newNode所指向的記憶體位置
}


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

    while (first != 0) {            // Traversal
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}


void LinkedList::Reverse(){

    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        return;
    }

    ListNode *previous = 0,
             *current = first,
             *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }                                  // preceding更新成NULL即跳出while loop

    current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
    first = current;                   // 更新first為current
}
