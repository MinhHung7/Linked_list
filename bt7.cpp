#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef struct node{
    double data;
    node* pnext=NULL;
}Node;

typedef struct linkedList{
    Node* Head = NULL;
    Node* Tail = NULL;
}LinkedList;

Node* makeNode(double data){
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

map<double, int>mapList;
map<double, int>mapArray;

void addEmpty(LinkedList&list, double data){
    Node* newNode = makeNode(data);
    list.Head = newNode;
    list.Tail = newNode;
    ++mapList[newNode->data];
}

void addTail(LinkedList& list, double data){
    if(isEmpty(list)){
        addEmpty(list, data);
    }
    else{
        Node*newNode = makeNode(data);
        list.Tail->pnext = newNode;
        list.Tail = newNode;
        ++mapList[newNode->data];
    }
}

void showList(LinkedList list){
    for(Node*i =list.Head; i!=NULL; i = i->pnext){
        cout<<i->data<<" ";
    }
}

void deleteList(LinkedList& list){
    while(list.Head!=NULL){
        Node* i = list.Head;
        list.Head = list.Head->pnext;
        delete i;
    }
}
vector<double>differ;
void bai1(LinkedList list, double* a, int n, map<double, int>mapList){
    bool checkExist = false;
    for(int i=0;i<n;++i){
        if(mapList[a[i]]==0){
            checkExist = true;
            cout<<a[i]<<" ";
            mapList[a[i]]=1;
        }
    }
    if(!checkExist){
        cout<<"Cac phan tu trong mang deu co trong list!!\n";
    }
}

void showArray(double *a, int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
}

void changeMang(LinkedList list, double* a, int& n){
    for(int i=0;i<n;++i){
        ++mapArray[a[i]];
    }
    for(Node*i = list.Head;i!=NULL; i=i->pnext){
        if(mapArray[i->data]){
            --mapArray[i->data];
        }
        else{
            ++n;
            a[n-1] = i->data;
        }
    }
    cout<<"Mang sau khi them: ";
    showArray(a, n);
}

void bai2(LinkedList list, double* a, int &n, map<double, int>mapList){
    cout<<"Ket qua bai 2: \n";
    for(int i=0;i<n;++i){
        if(mapList[a[i]]==0){
            differ.push_back(a[i]);
        }
        else --mapList[a[i]];
    }
    for(int i=0;i<differ.size();++i){
        addTail(list, differ[i]);
    }
    cout<<"List sau khi them: ";
    showList(list);
    cout<<"\n";
    changeMang(list, a, n);
}

int main(){
    cout<<"Nhap so phan tu cua mang: ";
    int n; cin>>n;
    double *a = new double[n];
    for(int i=0;i<n;++i){
        cout<<"Nhap phan tu thu "<<i<<" : ";
        cin>>a[i];
    }
    LinkedList list;
    cout<<"Nhap so phan tu trong list: ";
    int m; cin>>m;
    for(int i=0;i<m;++i){
        cout<<"Nhap phan tu thu "<<i<<" : ";
        double data; cin>>data;
        addTail(list, data);
    }

    cout<<"Ket qua bai 1: ";
    bai1(list, a, n, mapList);
    cout<<"\n";
    bai2(list, a, n, mapList);

    deleteList(list);
    delete[]a;
    return 0;
}