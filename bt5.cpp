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

void erase(LinkedList& list){
    bool ok;
    if(list.Head==list.Tail) return ;
    else{
        while(list.Head->pnext!=NULL && list.Head->data > list.Head->pnext->data){
            if(list.Head->pnext->pnext!=NULL){
                if(list.Head->data > list.Head->pnext->pnext->data){
                    list.Head = list.Head->pnext;
                }
                else break;
            }
            else{
                list.Head = list.Head->pnext;
            }
        }
        while(list.Head->pnext!=NULL && list.Head->data < list.Head->pnext->data){
            if(list.Head->pnext->pnext!=NULL){
                if(list.Head->pnext->data > list.Head->pnext->pnext->data){
                    if(list.Head->pnext->pnext->pnext!=NULL){
                        if(list.Head->pnext->data > list.Head->pnext->pnext->pnext->data){
                            list.Head->pnext = list.Head->pnext->pnext;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        list.Head->pnext = list.Head->pnext->pnext;
                    }
                }
                else break;
            }
            else{
                list.Tail = list.Head;
                list.Tail->pnext = NULL;
            }
        }
        Node* j = list.Head;
        Node*i = list.Head->pnext->pnext;

        for(;i!=NULL; i=i->pnext){
            if(i->pnext!=NULL){
                if(i->pnext->pnext!=NULL){
                    if(j->data < i->data && j->pnext->data < i->data && i->data > i->pnext->data && i->data > i->pnext->pnext->data){
                        j->pnext->pnext = i->pnext;
                        i = j->pnext;
                    }
                    else{
                        j = j->pnext;
                    }
                }
                else{
                    if(j->data < i->data && j->pnext->data < i->data && i->data > i->pnext->data){
                        j->pnext->pnext = i->pnext;
                        i = j->pnext;
                    }
                }
            }
            else{
                if(j->data < i->data && j->pnext->data < i->data){
                    list.Tail = j->pnext->pnext;
                    list.Tail->pnext = NULL;
                    break;
                }
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
    
    erase(list);

    cout<<"Cac phan tu sau khi xoa: ";
    for(Node* i = list.Head; i!=NULL; i=i->pnext){
        cout<<i->data<<" ";
    }
    return 0;
}