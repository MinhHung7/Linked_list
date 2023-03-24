#include<iostream>
#include<fstream>
using namespace std;

template<class T>
struct Node{
    Node<T>* pprev = NULL;
    Node<T>* pnext = NULL;
    T data;
};

template<class T>
struct doublyList{
    Node<T>* Head = NULL;
    Node<T>* Tail = NULL;
};

template<class T>
Node<T>* makeNode(T x){
    Node<T>* newNode = new Node<T>;
    if(newNode==NULL){
        cout<<"Khong du vung nho!!";
        return NULL;
    }
    else{
        newNode->data = x;
        return newNode;
    }
}

template<class T>
bool isEmpty(doublyList<T>list){
    return (list.Head==NULL && list.Tail==NULL);
}

template<class T>
void addDoublyList(doublyList<T>& list, T x){
    list.Head->data = x;
    list.Tail->data = x;
}

template<class T>
void insertHead(doublyList<T>& list, T x){
    if(isEmpty(list)){
        addDoublyList(list, x);
    }
    else{
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head;
        list.Head->pprev = newNode;
        list.Head = newNode;
    }
}
int main(){
    void* p = new void*;
    //int* p1 = new int;
    return 0;
}