#include <iostream>
using namespace std;
// 
class Node{
public:
    string data;
    int cnt;
    Node * prev;
    Node * next;

    Node(string data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
        this->cnt=1;
    }

};

class LinkedList{
public:
    Node * head;
    Node * tail;
    int size;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }

    void add(string data){
        Node * node=new Node(data);
        if(head==NULL){
            head=tail=node;
            
        }else if(!find(data)){
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
    }
    bool find(string data){
        Node * temp=tail;
        while(temp!=NULL){
            if(temp->data==data){
                temp->cnt++;
                return true;
            }else{
                temp=temp->prev;
            }
        }
        return false;

    }
    void sort_cnt(){
        Node * cur=head;
        while(cur){
            Node * temp=cur->next;
            while(temp){
                if((cur->cnt < temp->cnt) || (cur->cnt==temp->cnt && cur->data>temp->data)){
                    int x=cur->cnt;
                    cur->cnt=temp->cnt;
                    temp->cnt=x;
                    string val=cur->data;
                    cur->data=temp->data;
                    temp->data=val;                    
                }
                
                temp=temp->next;
            }
            cur=cur->next;

        }

    }

    void sort_data(){
        Node * cur=head;
        while(cur){
            Node * temp=cur->next;
            while(temp){
                if(cur->cnt==temp->cnt && cur->data>temp->data){
                    string val=cur->data;
                    cur->data=temp->data;
                    temp->data=val;                    
                }
                
                temp=temp->next;
            }
            cur=cur->next;

        }
    }
    void print(){
        freopen("output.txt","w",stdout);
        while(head!=NULL){
            
            cout << head->data << " " << head->cnt << endl;
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
    ll.sort_cnt();
    // ll.sort_data();
    ll.print();

    return 0;
}