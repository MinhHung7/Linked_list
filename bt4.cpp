#include<iostream>
using namespace std;

typedef struct node{
    double data;
    node* pnext = NULL;
}Node;

typedef struct linkedList{
    Node* Head = NULL;
    Node* Tail = NULL;
}LinkedList;

Node* makeNode(double data){
    Node* newNode = new Node;
    if(newNode==NULL){
        cout<<"Khong du vung nho cap phat!!";
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

void addEmptyList(LinkedList& list, double data){
    Node* newNode = makeNode(data);
    list.Head = newNode;
    list.Tail = newNode;
}

void addTail(LinkedList& list, double data){
    if(isEmpty(list)){
        addEmptyList(list, data);
    }
    else{
        Node* newNode = makeNode(data);
        list.Tail->pnext = newNode;
        list.Tail = newNode;
    }
}

void change(LinkedList& list, int pos, int n){
    if(pos==0 && list.Head->pnext!=NULL?list.Head->data > list.Head->pnext->data:0){
        if(list.Head->pnext->pnext!=NULL){
            if(list.Head->pnext->pnext->data < list.Head->data){
                list.Tail->pnext = list.Head;
                list.Head = list.Head->pnext;
                list.Tail = list.Tail->pnext;
                list.Tail->pnext = NULL;
            }
        }
        else{
            list.Tail->pnext = list.Head;
            list.Head = list.Head->pnext;
            list.Tail = list.Tail->pnext;
            list.Tail->pnext = NULL;
        }
    }
    else if(pos==1 && list.Head->data < list.Head->pnext->data){
        if(list.Head->pnext->pnext!=NULL && list.Head->pnext->data > list.Head->pnext->pnext->data){
            if(list.Head->pnext->pnext->pnext!=NULL){
                if(list.Head->pnext->data > list.Head->pnext->pnext->pnext->data){
                    list.Tail->pnext = list.Head->pnext;
                    list.Head->pnext = list.Head->pnext->pnext;
                    list.Tail = list.Tail->pnext;
                    list.Tail->pnext = NULL;
                }
            }
            else{
                list.Tail->pnext = list.Head->pnext;
                list.Head->pnext = list.Tail;
                list.Tail = list.Tail->pnext;
                list.Tail->pnext = NULL;
            }
        }
    }
    else{
        int countPos = 2;
        Node* i = list.Head->pnext->pnext;
        Node*j = list.Head;
        for(;i!=NULL;i = i->pnext, j = j->pnext, ++countPos){
            if(countPos==pos && j->data < i->data && j->pnext->data < i->data){
                if(i->pnext!=NULL){
                    if(i->data > i->pnext->data){
                        if(i->pnext->pnext!=NULL){
                            if(i->data > i->pnext->pnext->data){
                                list.Tail->pnext = i;
                                j->pnext->pnext = i->pnext;
                                i->pnext = NULL;
                                list.Tail = i;
                            }
                        }
                        else{
                            list.Tail->pnext = i;
                            j->pnext->pnext = i->pnext;
                            i->pnext = NULL;
                            list.Tail = i;
                        }
                    }
                }
                break;
            }
        }
    }
}

int main(){
    LinkedList list;
    cout<<"Nhap so luong phan tu can add vao list: ";
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cout<<"Nhap phan tu thu "<<i+1<<" : ";
        double data; cin>>data;
        addTail(list, data);
    }

    cout<<"Nhap vi tri can kiem tra: ";
    int pos; cin>>pos;
    
    change(list, pos, n);

    cout<<"Cac phan tu sau khi kiem tra: ";
    for(Node* i = list.Head; i!=NULL; i=i->pnext){
        cout<<i->data<<" ";
    }
    return 0;
}