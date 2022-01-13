#include <iostream>
using namespace std;
// done
class Node{
    public:
    char data;
    Node *next;

    Node(char data){
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

    void push(char data){
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
    char topData(){
        return top->data;
    }

    int size(){
        return this->sz;
    }

    bool empty(){
        return(sz==0);
    }
};



int main(){
    Stack *st=new Stack();
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(st->empty() || st->topData()!=s[i]){
            st->push(s[i]);
        }else{
            st->pop();
        }
    }
    if(st->empty()) cout << "YES";
    else cout << "NO";


    return 0;
}