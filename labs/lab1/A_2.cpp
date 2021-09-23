//55-task
#include <iostream>
using namespace std;
//done with code Akshabaev
//stack
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        this->top=NULL;
        this->sz=0;
    }

    void push(int data){
        Node *node=new Node(data);
        node->next=top;
        top=node;
        sz++;
    }

    void pop(){
        if(sz!=0){
            cout << top->data << endl;
            top=top->next;
            sz--;
        }else cout << "error" << endl;

    }

    void back(){
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

    // bool empty(){
    //     return (sz==0);
    // }

};

int main(){
    Stack *st=new Stack();

    string str;
    int x;

    while(cin >> str){
        if(str=="pop") st->pop();
        else if(str=="back") st->back();
        else if(str=="size") st->size();
        else if(str=="clear") st->clear();
        else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else{
            cin >> x;
            st->push(x);
            cout << "ok" << endl;
        }

    }


}
