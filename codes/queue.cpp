#include <iostream>
using namespace std;
//done
//QUeue вручнуюс пойнтером

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class Queue{
    public:
    Node *top;
    Node *back;
    Node *node;
    int sz;

    Queue(){
        this->top=NULL;
        this->back=NULL;
        this->node=NULL;
        this->sz=0;
    }

    void push(int data){
        node=new Node(data);
        if(top==NULL) top=node;
        else if(top->next==NULL && top!=NULL){
            top->next=node;
            back=node;
        }else{
            back->next=node;
            back=node;
        }
        sz++;
    }

    void pop(){
        if(sz!=0){
            cout << top->data << endl;
            top=top->next;
            sz--;
        }else cout << "error" << endl;

    }

    void first(){
        if(sz!=0) cout << top->data << endl;
        else cout << "error" << endl;
    }
    void size(){
        cout << sz << endl;
    }

    void clear(){
        top=NULL;
        sz=0;
        cout << "ok" << endl;
    }

};

int main(){
    Queue *qu=new Queue();

    string str;
    int x;

    while(cin >> str){
        if(str=="pop") qu->pop();
        else if(str=="front") qu->first();
        else if(str=="size") qu->size();
        else if(str=="clear") qu->clear();
        else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else{
            cin >> x;
            qu->push(x);
            cout << "ok" << endl;
        }

    }


}
