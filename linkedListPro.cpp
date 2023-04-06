#include<iostream>
#include<sstream>
#include<string>
#include<time.h>

using namespace std;

typedef struct node{
    string data;
    node* pnext=NULL;
}Node;

typedef struct linkedList{
    Node* Head=NULL;
    Node* Tail=NULL;
}LinkedList;

Node* makeNode(string data){
    Node* newNode = new Node;
    if(newNode==NULL){
        cout<<"Not enough memories to supply!!";
        return NULL;
    }
    else{
        newNode->data = data;
        return newNode;
    }
}

void addEmptyList(LinkedList & list, string data){
    Node* newNode = makeNode(data);
    list.Head = newNode;
    list.Tail  = newNode;
}

bool isEmpty(LinkedList list){
    return (list.Head==NULL && list.Tail==NULL);
}

void addTail(LinkedList& list, string data){
    if(isEmpty(list)){
        addEmptyList(list, data);
    }
    else{
        Node* newNode = makeNode(data);
        list.Tail->pnext = newNode;
        list.Tail =  newNode;
    }
}
void showList(LinkedList list){
    Node* i = list.Head;
    while(i->pnext!=NULL){
        cout<<i->data<<"->";
        i = i->pnext;
    }
    cout<<i->data<<"\n";
}

bool isNumber(Node* i){
    for(char c:i->data){
        if(c<'0' || c>'9') return false;
    }
    return true;
}

long long addSum(LinkedList list){
    long long sum=0;
    for(Node*i = list.Head;i!=NULL; i =i ->pnext){
        if(isNumber(i)){
            sum+=stoll(i->data);
        }
    }
    return sum;
}

void addMid(LinkedList& list, Node*& j, Node*& i){
    if(j->pnext==NULL) i->pnext = NULL;
    else i->pnext = j->pnext;
    j->pnext = i;
}

void splitNode(LinkedList& list){
    if(list.Head==NULL && list.Tail==NULL) return;
    else{
        Node* j = list.Head;
        // Xu li list.Head = "nguyen van a";
        stringstream token(list.Head->data);
        string word;
        while(token>>word){
            Node* i = makeNode(word);
            addMid(list, j, i);
            //if(temp->data=="") temp = i;
            j = j->pnext;
        }
        Node* del = list.Head;
        list.Head = list.Head->pnext;
        delete del;
        // Xu li phan con lai
        while(j->pnext!=NULL){
            Node* temp= j;
            string s = j->pnext->data;
            stringstream token(s);
            string word;
            while(token>>word){
                Node*  i = makeNode(word);
                j = j->pnext;
                addMid(list, j, i);
            }
            Node* del = temp->pnext;
            temp->pnext = temp->pnext->pnext;
            delete del;
            j = j->pnext;
        }
    }
}

bool checkSum(int num){
    while(num){
        if(num%10==7) return true;
        num/=10;
    }
    return false;
}
bool leftflag=false, rightflag=false, midflag = false;
void findMinWay(LinkedList& list, int k, Node*& posLeft, Node*& posRight, Node*& posAim){
    
    int sumLeft=0; // Tinh tong node tu dau den ben trai aim, neu thoa thi so sanh, ko thi tru bot;
    int i=0; 
    Node* flag = list.Head;
    while(i<=k){
        if(i==k) posAim = flag;
        sumLeft += stoi(flag->data);
        flag = flag->pnext;
        ++i;
    }
    // Co tong cac so tu 1->k
    int minLeftDirect=0, leftStep = 0;
    Node* leftNode = list.Head;  
    while(leftNode!=posAim){
        if(checkSum(sumLeft)){
            posLeft = leftNode;
            minLeftDirect = k - leftStep;
            leftflag = true;
        }
        sumLeft-=stoi(leftNode->data);
        leftNode = leftNode->pnext;
        ++leftStep;
    }
    
    int rightSum = stoi(posAim->data);
    if(checkSum(rightSum)){
        midflag = true;
        rightflag = false;
        leftflag = false;
        return;
    }
    else{
        Node* rightNode = posAim->pnext;
        int minRightDirect = 0;
        while(rightNode!=NULL){
            ++minRightDirect;
            rightSum+=stoi(rightNode->data);
            if(checkSum(rightSum)){
                posRight = rightNode;
                rightflag = true;
                break;
            }
            rightNode = rightNode->pnext;
        }
        if(leftflag && rightflag){
            if(minLeftDirect < minRightDirect){
                rightflag = false;
            }
            else if(minLeftDirect > minRightDirect){
                leftflag = false;
            }
        }
    }

}

void convertList(LinkedList list, Node* pos){
    cout<<"List after converting: ";
    Node*i = list.Head;
    list.Tail->pnext = i;
    list.Head = pos->pnext;
    list.Tail = pos;
    list.Tail->pnext = NULL;
    showList(list);
}
int main(){
    srand(time(NULL));
    // linkedList list;
    // cout<<"Enter number of elements of list: ";
    int quantity; 
    //cin>>quantity;
    // cin.ignore();
    // for(int i=0;i<quantity;++i){
    //     cout<<"Enter data for node "<<i<<" : ";
    //     string data; getline(cin, data);
    //     addTail(list,data);
    // }
    // cout<<"List: ";
    // showList(list);
    // cout<<"Sum of numbers of list: "<<addSum(list)<<"\n";
    // splitNode(list);
    // cout<<"List after splitting: ";
    // showList(list);
    // cout<<"Sum of numbers of list after splitting: "<<addSum(list)<<"\n";

    cout<<"Bai 2: \n";
    int k = 3;
    LinkedList list2;
    cout<<"Enter number of elements of list: ";
    cin>>quantity;
    cin.ignore();
    for(int i=0;i<quantity;++i){
        cout<<"Enter data for node "<<i<<" : ";
        string data; getline(cin, data);
        addTail(list2,data);
    }
    cout<<"K la: "<<k<<"\n";
    if(k>=quantity){
        cout<<"K khong hop le!!!\n";
    }
    else{
        Node* posLeft, *posRight, *posAim;
        findMinWay(list2, k, posLeft, posRight, posAim);
        if(midflag){
            cout<<"Min way is: "<<posAim->data<<"\n";
            convertList(list2, posAim);
        }
        else{
            if(rightflag){
                cout<<"Min way is: ";
                for(Node* j = posAim; j!=posRight;j=j->pnext){
                    cout<<j->data<<"->";
                }
                cout<<posRight->data<<"\n";
            }
            if(leftflag){
                cout<<"Min way is: ";
                for(Node* j = posLeft; j!=posAim;j=j->pnext){
                    cout<<j->data<<"->";
                }
                cout<<posAim->data<<"\n";
            }
            if(rightflag){
                convertList(list2, posRight);
            }
            if(leftflag){
                convertList(list2, posLeft);
            }
        }
    }
    return 0;
}