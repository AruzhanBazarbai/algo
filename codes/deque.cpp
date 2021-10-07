// deque
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

    
};

int main(){
    Deque *dq=new Deque();
    string str;

    while (cin >> str){
        if (str=="push_back"){
            int x;
            cin >> x;
            dq->push_back(x);
            cout << "ok" << endl;
        }
        else if (str=="pop_back") dq->pop_back();
        else if (str=="push_front"){
            int x;
            cin >> x;
            dq->push_front(x);
            cout << "ok" << endl;
        }
        else if (str=="pop_front") dq->pop_front();
        else if (str=="size") cout << dq->sz << endl;
        else if (str=="back") dq->back();
        else if(str=="front") dq->front();
        else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else if(str=="clear"){
            dq->clear();
            cout << "ok" << endl;
        }
    }

}