#include<iostream>
#include<vector>
using namespace std;

template<class T> // Khai bao node
struct Node{
    T data;
    Node<T>*pnext = NULL;
};

template<class T> // Khai bao linked_list
struct Linked_list{
    Node<T>* Head = NULL;
    Node<T>* Tail = NULL;
};

template<class T> // Ham makeNode
Node<T>* makeNode(T x){
    Node<T>* newNode = new Node<T>;
    if(newNode==NULL){
        cout<<"Khong du vung nho!";
        return NULL;
    }
    else{
        newNode->data = x;
        return newNode;
    }
}
template<class T> // Kiem tra linked_list rong
bool isEmpty(Linked_list<T>list){ 
    return (list.Head==NULL && list.Tail==NULL);
}

template<class T>  // Ham add node vao linked_list rong
void addLinkedList(Linked_list<T>& list, T x){  // list rong
    Node<T>* newNode = makeNode(x);
    list.Head = newNode;
    list.Tail = newNode;
}

template<class T>
void insertHead(Linked_list<T>& list, T x){
    if(isEmpty(list)){
        addLinkedList(list, x);
    }
    else{
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head;
        list.Head = newNode;
    }
}

template<class T>
void insertTail(Linked_list<T>& list, T x){
    if(isEmpty(list)){
        addLinkedList(list, x);
    }
    else{
        Node<T>* newNode = makeNode(x);
        list.Tail->pnext = newNode;
        list.Tail = newNode;
    }
}

template<class T>
void addBehind(Linked_list<T>& list,T value, T x){
    Node<T>* i = list.Head;
    if(list.Head->data==value){
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head->pnext;
        list.Head->pnext = newNode;
        i = i->pnext;
    }
    while(i->pnext!=NULL){
        if(i->pnext->data==value){
            Node<T>* newNode = makeNode(x);
            newNode->pnext = i->pnext->pnext;
            i->pnext->pnext = newNode;
            i = i->pnext;
        }
        i = i->pnext;
    }
}

template<class T>
void addFront(Linked_list<T>& list, int x, int value){
    Node<T>* i = list.Head;
    if(list.Head->data==value){
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head;
        list.Head = newNode;
    }
    while(i->pnext!=NULL){
        if(i->pnext->data == value){
            Node<T>* newNode = makeNode(x);
            newNode->pnext = i->pnext;
            i->pnext = newNode;
            i = i->pnext;
        }
        i = i->pnext;
    }
}

template<class T>
void change(Linked_list<T>& list, int value, int x){
    for(Node<T>*i = list.Head; i!=NULL; i = i-> pnext){
        if(i->data==value){
            i->data = x;
        }
    }
}

template<class T>
void erase(Linked_list<T>& list, int value){
    Node<T>* i = list.Head;
    if(list.Head->data==value){
        while(i->pnext!=NULL && i->pnext->data==value){
            i = i->pnext;
        }
        list.Head = i->pnext;
        i = i->pnext;
    }
    while(i->pnext!=NULL){
        if(i->pnext->data==value){
            Node<T>* j = i->pnext;
            while(j!=NULL &&  j->data==value){
                j = j->pnext;
            }
            if(j!=NULL){
                i->pnext = j;
            }
            else{
                i->pnext = NULL;
                list.Tail = i;
            }
        }
        else  i = i->pnext;
    }
}

int main(){
    Linked_list<int> list;
    insertHead(list, 7);
    insertTail(list, 7);
    insertTail(list, 3);
    insertTail(list, 7);
    insertTail(list, 7);
    insertTail(list, 4);
    insertTail(list, 7);
    insertTail(list, 7);

    // addBehind(list, 7, 7);
    // addFront(list, 7, 7);
    //change(list, 7, 5);
    erase(list, 7);
    for(Node<int>* i = list.Head;i!=NULL;i=i->pnext){
        cout<<i->data<<" ";
    }
}