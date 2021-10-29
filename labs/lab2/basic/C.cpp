#include <iostream>
using namespace std;
// /
class Node{
public:
    string data;
    int sz;
    Node * prev;
    Node * next;

    Node(string data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
        this->sz=1;
    }

};

class LinkedList{
public:
    Node * head;
    Node * tail;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }

    void add(string data){
        Node * node=new Node(data);
        if(head==NULL){
            head=tail=node;
            
        }else{
            Node * temp=head;
            while(temp!=NULL){
                if(temp->data==data){
                    temp->sz++;
                    break;
                }else{
                    temp=temp->next;
                }
            }
            if(temp==NULL){
                node->prev=tail;
                tail->next=node;
                tail=node;
            }
        }
    }
    bool find(string data){
        Node * temp=tail;
        while(temp!=NULL){
            if(temp->data==data){
                temp->sz++;
                return true;
            }else{
                temp=temp->prev;
            }
        }
        return false;

    }
    void sortLL(){
        Node * temp=tail;
        Node * cur=tail;
        while(cur!=NULL){
            temp=cur->prev;
            while(temp!=NULL){
                if(cur->sz>temp->sz || (cur->sz==temp->sz && temp->data > cur->data)){
                    string s=cur->data;
                    int x=cur->sz;
                    cur->data=temp->data;
                    cur->sz=temp->sz;
                    temp->data=s;
                    temp->sz=x;
                }
                temp=temp->prev;
            }
            cur=cur->prev;
        }
    }
    
    void print(){
        freopen("output.txt","w",stdout);
        while(head!=NULL){
            
            cout << head->data << " " << head->sz << endl;
            head=head->next;
        }
        fclose(stdout);
    }
    

};

int main(){
    freopen("input.txt","r",stdin);
    
    string str;
    LinkedList ll;
    while(cin >> str){
        ll.add(str);
    }
    ll.sortLL();
    // ll.sort_data();
    ll.print();

    return 0;
}