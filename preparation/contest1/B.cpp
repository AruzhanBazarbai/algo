// /*
// Problem B. AaAaAaAAaAaAAa
// Input file: standard input
// Output file: standard output
// Time limit: 4 seconds
// Memory limit: 256 megabytes
// You are given q (1 ≤ q ≤ 6 ∗ 105
// ) queries. Also there is an empty array a. There is two types of queries:
// 1 x (1 ≤ x ≤ 1000): Add x to the end of array a
// 2: Reverse the array a
// Output the array after q queries.
// Input
// First line contains q - the number of queries. The next q lines contain queries.
// Output
// Output the array a after all queries.
// */
#include <iostream>
using namespace std;
// done
class Node{
    public:
    int data;
    Node * prev, *next;
    Node(int data){
        this->prev=NULL;
        this->next=NULL;
        this->data=data;
    }
};

class Deque{
    public:
    Node * head;
    Node * tail;
    int sz;
    Deque(){
        this->head=NULL;
        this->tail=NULL;
        this->sz=0;
    }

    void push_front(int data){
        Node * node=new Node(data);
        if(head==NULL){
            head=tail=node;
            sz++;
        }else{
            node->next=head;
            head->prev=node;
            head=node;
            sz++;
        }
    }

    void push_back(int data){
        Node * node=new Node(data);
        if(head==NULL){
            head=tail=node;
            sz++;
        }else{
            node->prev=tail;
            tail->next=node;
            tail=node;
            sz++;
        }
    }
    void front(){
        if(sz==0) cout << "error" << endl;
        else cout << head->data << endl;
    }

    void back(){
        if(sz==0) cout << "error" << endl;
        else cout << tail->data << endl;
    }

    void pop_front(){
        if(sz==0) cout << "error" << endl;
        else{
            cout << head->data << endl;
            head=head->next;
            if(head==NULL){
                head=tail=NULL;
                sz=0;
            }else{
                head->prev=NULL;
                sz--;
            }
            
            
        }

    }

    void pop_back(){
        if(sz==0) cout << "error" << endl;
        else{
            cout << tail->data << endl;
            tail=tail->prev;
            if(tail==NULL){
                head=tail=NULL;
                sz=0;
            }else{
                tail->next=NULL;
                sz--;
            }
        }
    }

    void clear(){
        head=tail=NULL;
        sz=0;
    }
    void print_front(){
        while(head!=NULL){
            cout << head->data << " ";
            head=head->next;
        }
    }
    void print_back(){
        while(tail!=NULL){
            cout << tail->data << " ";
            tail=tail->prev;
        }
    }

    
};

int main(){
    Deque *dq=new Deque();
    bool k=true;
    int n,x,t;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==1){
            cin >> t;
            if(k){
                dq->push_back(t);
            }else{
                dq->push_front(t);
            }

        }else if(x==2){
            k=!k;
        }

    }
    if(k) dq->print_front();
    else dq->print_back();
}