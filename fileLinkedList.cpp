#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

typedef struct node{
    int data;
    node* pnext = NULL;
}Node;

typedef struct linkedList{
    Node* Head = NULL;
    Node* Tail = NULL;
}LinkedList;

bool isEmpty(LinkedList list){
    return (list.Head == NULL && list.Tail == NULL);
}

Node* makeNode(int data){
    Node* newNode = new Node;
    if(newNode==NULL){
        cout<<"Not enough memory";
        return NULL;
    }
    else{
        newNode->data = data;
        return newNode;
    }
}

void addEmptyList(LinkedList&list, int data){
        Node* newNode = makeNode(data);
        list.Head = newNode;
        list.Tail = newNode;
}

void addHead(LinkedList& list, int data){
    if(isEmpty(list)){
        addEmptyList(list, data);
    }
    else{
        Node* newNode = makeNode(data);
        newNode->pnext = list.Head;
        list.Head = newNode;
    }
}
int countt=0;

void addTail(LinkedList& list, int data){
    if(isEmpty(list)){
        addEmptyList(list, data);
        ++countt;
    }
    else{
        Node* newNode = makeNode(data);
        list.Tail->pnext = newNode;
        list.Tail = newNode;
        ++countt;
    }
}
vector<int>vt(100000000,0);
void enterTailDataFromFile(LinkedList& list, string fileName){
    ifstream openToRead;
    openToRead.open(fileName, ios::in);
    if(openToRead.is_open()){
        string reader;
        while(!openToRead.eof()){
            getline(openToRead, reader);
            int data = stoi(reader);
            addTail(list, data);
        }
        openToRead.close();
    }
    else{
        cout<<"Can not open file";
    }
}

void showAllList(LinkedList list){
    cout<<"List: ";
    for(Node* i = list.Head; i!=NULL; i = i->pnext){
        cout<<i->data<<" ";
    }
}

void interchangeSort(LinkedList& list){
    for(Node*i = list.Head; i->pnext!=NULL; i = i->pnext){
        for(Node* j = i->pnext ;j!=NULL; j=  j->pnext){
            if(i->data > j->data){
                swap(i->data, j->data);
            }
        }
    }
}

LinkedList reserve(LinkedList list){
    Node* i = list.Head;
    LinkedList j;
    for(; i!=NULL; i=i->pnext){
        addHead(j, i->data);
    }
    return j;
}

bool palindrome(LinkedList list){
    LinkedList newList = reserve(list);
    Node* i =list.Head;
    Node* j = newList.Head;
    for(; i!=NULL;i=i->pnext){
        if(i->data != j->data) return false;
        else{
            j=j->pnext;
        }
    }
    return true;
}

void deleHead(LinkedList& list){
    if(list.Head==NULL) return;
    Node*i = list.Head->pnext;
    delete list.Head;
    list.Head = i;
}
// 1
// 
void deleTail(linkedList& list){
    if(list.Head==NULL) return;
    if(list.Head->pnext==NULL){
        delete list.Head;
        list.Head = NULL;
        list.Tail = NULL;
    }
    Node* i  = list.Head;
    for(; i->pnext->pnext!=NULL ;i = i->pnext);
    delete list.Tail;
    i->pnext = NULL;
    list.Tail = i;
}
// 1 2 2 
int count = 0;
void deleMid(LinkedList& list){
    for(Node*i = list.Head;i!=NULL; i=i->pnext){
        ++count;
    }
    //  count 1 2 3 4 5 
    //  dem 0 1 2 3 4 
    int dem=0;
    if(count<=2){
        delete list.Head;
        delete list.Tail;
        list.Head=NULL;
        list.Tail =NULL;
        return;
    }
    if(count%2==0){
        for(Node*i = list.Head;i!=NULL ; i=i->pnext){
            if(dem==count/2-2){
                Node* q = i->pnext;
                Node* k = q->pnext;
                i->pnext = k->pnext;
                delete q;
                delete k;
                break;
            }
            ++dem;
        }
    }
    else{
        for(Node*i = list.Head;i!=NULL ; i=i->pnext){
            if(dem==count/2-1){
                Node* q = i->pnext;
                i->pnext = q->pnext;
                delete q;
                break;
            }
            ++dem;
        }
    }
}

void eraseAll(LinkedList& list){
    for(Node*i = list.Head;i->pnext!=NULL;i=i->pnext){
        Node* t = i;
        i = i->pnext;
        delete t;
        list.Head = i;
    }
    delete list.Head;
    list.Head = list.Tail = NULL;
}

bool check(Node*i, int k){
    for(int j=0;j<k;++j){
        if(i->pnext==NULL){
            return false;
        }
        i = i->pnext;
    }
    return true;
}

bool ktra(Node*i, int k){
    Node* temp = i->pnext;
    for(int j=1; j<=k;++j){
        if(i->data < temp->data) return false;
        else temp=temp->pnext;
    }
    return true;
}

void nhapMang(int *&a, int n){
    for(int i=0;i<n;++i){
        cout<<"nhap phan tu "<<i<<": ";
        int x; cin>>x;
        a[i] = x;
    }
}

void bai1(int*a, int n, LinkedList list){
    for(int i=0;i<n;++i){
        bool checkEx = true;
        for(Node*j = list.Head;j!=NULL; j = j->pnext){
            if(a[i]==j->data){
                checkEx = false;
                break;
            }
        }
        if(checkEx){
            cout<<a[i]<<" ";
        }
    }
}

void bai2(int*a, int n, LinkedList list){
    for(int i=0;i<n;++i){
        if(vt[a[i]]==0){
            cout<<a[i]<<" ";
        }
        ++vt[a[i]];
    }
    for(Node*j= list.Head; j!=NULL;j = j->pnext){
        bool checkEx =true;
        for(int i=0;i<n;i++){
            
            if(a[i]==j->data){
                checkEx = false;
                break;
            }
        }
        if(checkEx){
            
        }else{
     if(vt[j->data]!=0){
            --vt[j->data];
        }
        else{
            cout<<j->data<<" ";
            ++vt[j->data];
        }
        }
       

    }
} 

int main(){
    int n;
    cout<<"Nhap so phan tu trong mang: "; cin>>n;
    int*a  = new int[n];
    nhapMang(a,n);

    LinkedList list;
    cout<<"Nhap so phan tu trong dslk: "; int m; cin>>m;
    for(int i=0;i<m;++i){
        cout<<"Nhap phan tu "<<i<<": ";
        int x; cin>>x;
        addTail(list, x);
    }

    cout<<"Bai 1: ";
    bai1(a, n, list);
    cout<<"\n";
cout<<"Danh sach lien ket sau khi them: ";
    bai2(a, n, list);
    for(int i=0;i<=100000000;++i) vt[i]=0;
    cout<<"\nMang sau khi them: ";
    bai2(a, n, list);
    return 0;
}