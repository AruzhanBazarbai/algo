#include <iostream>

using namespace std;
//
class Node{
    public:
    int data;
    Node * next;
    Node * prev;

    Node(int data){
       this->data = data;
       this->next = NULL; 
       this->prev = NULL;
    }

    //node(int x):val(x),next(NULL),prev(NULL){}

};

class LinkedList{
    public:
    Node * head;   
    Node * tail;
    int sz;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->sz = 0;
    }

    void add(int data){
        Node * node = new Node(data);
        sz++;
        if(head == NULL){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;   
        }
    }

    Node * find(int data){
        Node * temp = head;
        Node * result = NULL;
        while(temp != NULL){
            if(temp->data == data){
                result = temp;
                break;
            }
            temp = temp->next;
        }   
        return result;
    }

    void dl(Node * n){
        if(n != NULL){
            sz--;
            if(n->prev == NULL && n->next == NULL){
                head = tail = NULL;
            }else if(n->prev != NULL && n->next != NULL){
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }else if(n->prev == NULL && n->next != NULL){
                head = n->next;
                n->next->prev = NULL;
            }else if(n->next == NULL && n->prev != NULL){
                tail = n->prev;
                n->prev->next = NULL;  
            }
            delete n;
        }
    }

    void dl(int data){
        Node * temp = find(data);
        dl(temp);
    }

    void print(){
        Node * temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty(){
        return sz == 0;
    }

};

int main(){

    LinkedList * l = new LinkedList();

    return 0;
}