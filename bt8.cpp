#include<iostream>
#include<map>
#include<time.h>
#include<vector>

using namespace std;

typedef struct node{
    int data;
    node* pnext=NULL;
}Node;

typedef struct linkedList{
    Node* Head = NULL;
    Node* Tail = NULL;
}LinkedList;

Node* makeNode(int data){
    Node* newNode = new Node;
    if(newNode==NULL){
        cout<<"Khong du bo nho de cap phat!!";
        return NULL;
    }
    else{
        newNode->data = data;
        return newNode;
    }
}

bool isEmpty(LinkedList list){
    return (list.Head==NULL && list.Tail==NULL);
}

void addEmpty(LinkedList&list, int data){
    Node* newNode = makeNode(data);
    list.Head = newNode;
    list.Tail = newNode;
}

void addTail(LinkedList& list, int data){
    if(isEmpty(list)){
        addEmpty(list, data);
    }
    else{
        Node*newNode = makeNode(data);
        list.Tail->pnext = newNode;
        list.Tail = newNode;
    }
}


void deleteList(LinkedList& list){
    while(list.Head!=NULL){
        Node* i = list.Head;
        list.Head = list.Head->pnext;
        delete i;
    }
}

void bai1(LinkedList& list){
    int soChan=2, soLe=1;
    bool chan = list.Head->data%2==0;
    if(chan){
        Node *newNode = makeNode(soLe);
        newNode->pnext = list.Head;
        list.Head = newNode;
    }
    else{
        Node* newNode = makeNode(soChan);
        newNode->pnext = list.Head;
        list.Head = newNode;
    }
    Node* i = list.Head->pnext;
    while(i->pnext!=NULL){
        if(chan){
            if(i->pnext->data%2==0){
                Node *newNode = makeNode(soLe);
                newNode->pnext = i->pnext;
                i->pnext = newNode;
                i = newNode->pnext;
            }
            else{
                chan = false;
                i=i->pnext;
            }
        }
        else{
            if(i->pnext->data%2==0){
                i = i->pnext;
                chan=true;
            }
            else{
                Node *newNode = makeNode(soChan);
                newNode->pnext = i->pnext;
                i->pnext = newNode;
                i = newNode->pnext;
            }
        }
    }
    cout<<"Ket qua bai 1: ";
    for(Node*i = list.Head;i!=NULL; i = i->pnext){
        cout<<i->data<<" ";
    }
}
void bai2(LinkedList& list){
    if(list.Head->data%2==0){
        if(list.Head->pnext==NULL){
            Node*i = list.Head;
            list.Head = NULL;
            list.Tail =NULL;
            delete i;
        }
        else{
            Node*i = list.Head;
            list.Head = list.Head->pnext;
            delete i;
        }
    }
    Node* i =list.Head;
    while(i->pnext!=NULL && i->pnext->pnext!=NULL){
        if(i->pnext->pnext==NULL){
            if(i->pnext->data%2==0){
                Node*j = i->pnext;
                list.Tail=i;
                i->pnext=NULL;
                delete j;
            }
            i = i->pnext;
        }
        else{
            if(i->pnext->data%2==0){
                Node*j =i->pnext;
                i->pnext = j->pnext;
                delete j;
            }
            i = i->pnext;
        }
    }
    if(i->pnext!=NULL && i->pnext->data%2==0){
        Node*j = i->pnext;
        i->pnext=NULL;
        delete j;
    }
    cout<<"\nKet qua bai 2: ";
    for(Node*i = list.Head;i!=NULL; i = i->pnext){
        cout<<i->data<<" ";
    }
}
int main(){
    srand(time(NULL));
    LinkedList list;
    cout<<"Nhap so phan tu cho list: ";
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int data = rand()%20+1;
        addTail(list, data);
    }
    bai1(list);
    bai2(list);
    deleteList(list);
    return 0;
}