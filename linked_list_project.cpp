#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Node{
    int data;
    Node<T>* pprev = NULL;
    Node<T>* pnext = NULL;
};

template<class T>
struct DoubleList{
    Node<T>* Head = NULL;
    Node<T>* Tail = NULL;
};

template<class T>
bool isEmpty(DoubleList<T> list){
    return (list.Head==NULL && list.Tail==NULL);
}

template<class T>
Node<T>* makeNode(T x){
    Node<T>* newNode = new Node<T>;
    if(newNode==NULL){
        cout<<"Khong du vung nho!!";
    }
    else{
        newNode->data = x;
        return newNode;
    }
}

template<class T>
void addEmpty(DoubleList<T>&list, T x){
    Node<T>* newNode = makeNode(x);
    list.Head = newNode;
    list.Tail = newNode;
}

template<class T>
void addHead(DoubleList<T>& list, T x){
    if(isEmpty(list)){
        addEmpty(list, x);
    }
    else{
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head;
        list.Head->pprev = newNode;
        list.Head = newNode;
    }
}

template<class T>
void addTail(DoubleList<T>& list, int x){
    if(isEmpty(list)){
        addEmpty(list, x);
    }
    else{
        Node<T>* newNode = makeNode(x);
        list.Tail->pnext = newNode;
        newNode->pprev = list.Tail;
        list.Tail = newNode;
    }
}

template<class T>
void eraseMore(DoubleList<T>&list){
    vector<pair<T, int>> mark;
    Node<T>* i = list.Head;
    while(i!=NULL){
        bool check = false;
        for(int j=0;j<mark.size();++j){
            if(mark[j].first==i->data){
                check = true;
                if(i->pnext==NULL){
                    list.Tail = i->pprev;
                    Node<T>* temp = i;
                    i = i->pprev;
                    temp->pprev->pnext = NULL;
                    temp->pprev = NULL;
                    i = i->pnext;
                }
                else{ i->pnext;
                    i->pprev->pnext = i->pnext;
                    i->pnext->pprev = i->pprev;
                    Node<T>* temp = i;
                    i = i->pnext;
                    temp->pprev = NULL;
                    temp->pnext = NULL;
                }
                break;
            }
        }
        if(!check){
            mark.push_back({i->data, 1});
            i = i->pnext;
        }
    }
}
template<class T>
void insertionSort(DoubleList<T>& list){
    Node<T>* i = list.Head->pnext;
    while(i!=NULL){
        if(i->data < i->pprev->data){
            Node<T>* j = i;
            while(j->pprev!=NULL && j->data < j->pprev->data){
                T temp = j->data;
                j->data = j->pprev->data;
                j->pprev->data = temp;
                j = j->pprev;
            }
        }
        i = i->pnext;
    }
}

template<class T>
void addElement(DoubleList<T>& list, T x){
    if(x < list.Head->data){
        Node<T>* newNode = makeNode(x);
        newNode->pnext = list.Head;
        list.Head->pprev = newNode;
        list.Head = newNode;
    }
    else if(x > list.Tail->data){
        Node<T>* newNode = makeNode(x);
        newNode->pprev = list.Tail;
        list.Tail->pnext = newNode;
        list.Tail = newNode;
    }
    else{
        Node<T>* i = list.Head;
        while(i->pnext!=NULL){
            if(i->pnext->data > x){
                Node<T>* newNode = makeNode(x);
                newNode->pnext = i->pnext;
                i->pnext = newNode;
                newNode->pprev = i;
                newNode->pnext->pprev = newNode; 
                break;
            }
            else{
                i = i->pnext;
            }
        }
    }
}

template<class T>
void enterDoubleList(DoubleList<T>& list){
    cout<<"Nhap so luong phan tu trong list: ";
    int n; cin>>n;
    while(n--){
        T data; cin>>data;
        addTail(list, data);
    }
}

template<class T>
void showList(DoubleList<T> list){
    for(Node<T>*i = list.Head; i!=NULL; i = i->pnext){
        cout<<i->data<<" ";
    }
}

template<class T>
void showDecre(DoubleList<T>list){
    for(Node<T>*i = list.Tail; i!=NULL; i=i->pprev){
        cout<<i->data<<" ";
    }
}
int main(){
    DoubleList<int>list;
    enterDoubleList(list);
    eraseMore(list);
    insertionSort(list);
    addElement(list, 7);
    showDecre(list);
    return 0;
}