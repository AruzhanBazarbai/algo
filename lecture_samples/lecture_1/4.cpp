#include <iostream>
using namespace std;

// b Node(20) b->a then b->top при удаление верхнего элемента, просто перекинем топ на пред.элемент
// a Node(10)

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
        top=NULL;
        sz=0;

    }

    void push(int data){
        //node(30) top
        //node(20)
        //node(10)
        Node *node=new Node(data);
        node->next=top;
        top=node;
        sz++;
    }

    void pop(){
        if(top!=NULL){
            top=top->next;
            sz--;
        }
    }

    int size(){
        return this->sz;
    }

    bool empty(){
        // if(sz==0) return true;
        // return false;
        return(sz==0);
    }
};



int main(){
    //если без пойнтера делаем, то с точкой обращаемся
    // Stack st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // cout << st.size() << endl;
    // здесь st сам экземпляр будет, а если через звездочку то храним именно адрес


    Stack *st=new Stack();
    st->push(10);
    st->push(20);
    st->push(30);
    st->pop();
    st->pop();
    cout << st->size() << endl;
    cout << st->top->data << endl;



    return 0;
}