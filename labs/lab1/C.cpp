//61-task
#include <iostream>
using namespace std;
//
//Deque

class Node{
    public:
    int data;
    Node *prev;

    Node(int data){
        this->data=data;
        this->prev=NULL;
    }

};

class Deque{
    public:
    Node *top;
    Node *tail;
    Node *node;
    Node *res;
    Node *t;
    int sz;

    Deque(){
        this->top=NULL;
        this->tail=NULL;
        this->node=NULL;
        this->res=NULL;
        this->t=NULL;
        this->sz=0;
    }

    void push_front(int data){
        Node *node=new Node(data);

        if(top==NULL){
            tail=node;
            // res=tail;
            top=node;
            // t=top;
            // cout << "ok---1" << endl;

        }else if(top!=NULL && top->prev==NULL){
            res=node;
            tail->prev=res;
            

            t=top;
            node->prev=t;
            top=node;
        }
        else{
            res->prev=node;
            res=node;
            node->prev=top;
            top=node;
            
            // cout << "ok---2" << endl;

        }
        // cout << "ok----3" << endl;

        
        

        sz++;
        cout << "ok" << endl;
    }

    void push_back(int data){
        Node *node=new Node(data);
        if(tail==NULL){
            tail=node;
            top=node;
        }else if(tail!=NULL && tail->prev==NULL){
            t=node;
            top->prev=t;
            
            res=tail;
            node->prev=res;
            tail=node;
        }
        else{
            t->prev=node;
            t=node;
            node->prev=tail;
            tail=node;
        
        }
        cout << "ok" << endl;
        sz++;
        
        
    }

    void pop_front(){
        if(sz==0) cout << "error" << endl;
        else{
            cout << top->data << endl;
            top=top->prev;
            sz--;
        }
    }

    void pop_back(){
        if(sz==0) cout << "error" << endl;
        else{
            cout << tail->data << endl;
            tail=tail->prev;
            sz--;
        }
    }

    void size(){
        cout << sz << endl;
    }

    void front(){
        if(sz==0) cout << "error" << endl;
        else cout << top->data << endl;
    }

    void back(){
        if(sz==0) cout << "error" << endl;
        else cout << tail->data << endl;
    }
    
    void clear(){
        sz=0;
        tail=NULL;
        top=NULL;
        cout << "ok" << endl;
    }

};

int main(){
    Deque *d=new Deque();

    string str;
    int x;

    while(cin >> str){
        if(str=="pop_front") d->pop_front();
        else if(str=="pop_back") d->pop_back();
        else if(str=="size") d->size();
        else if(str=="clear") d->clear();
        else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else if(str=="front") d->front();
        else if(str=="back") d->back();
        else if(str=="push_front"){
            cin >> x;
            d->push_front(x);
            // cout << "ok" << endl;
        }
        else{
            cin >> x;
            d->push_back(x);
            // cout << "ok" << endl;
        }

    }


}