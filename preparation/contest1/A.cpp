// /*
// Problem A. Jonathan the Poet
// Input file: standard input
// Output file: standard output
// Time limit: 1 second
// Memory limit: 256 megabytes
// Jonathan the Poet has finished his new poem recently. But something went wrong and now he thinks
// that rhyme could be better. He believe that applying cyclic shift by K positions will fix the problem.
// Jonathan’s new poem is a sequential list of words. Jonathan is tired and asked your help to find such
// cyclic shift.
// To clarify, you are given a poem of N words as a single linked list. Your task is to write function that
// shifts linked list by K positions and returns the head of new linked list.
// Input
// The first line contains two integers N and K (1 6 K < N 6 105
// ) - number of words in the poem.
// The second line contains N words that consist of lowercase latin letters. It is guaranteed that the total
// length of all words does not exceed 3 · 105
// .
// Output
// If your function is implemented correctly, program will print the poem with order of words shifted by K
// positions.
// */
#include <iostream>
using namespace std;
// done/done
class Node{
    public:
    string data;
    Node * next;
    Node * prev;
    Node(string data){
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

    void add(string data){
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

    void cyclicShift(int k){
        Node * cur=NULL;
        Node * cur_tail=NULL;
        Node * temp=head;
        while(k--){
            Node * node=new Node(head->data);
            if(cur==NULL) cur=cur_tail=node;
            else{
                cur_tail->next=node;
                node->prev=cur_tail;
                cur_tail=node;
            }
            head=head->next;
            head->prev=NULL;

        }
        while(cur!=NULL){
            Node * n=new Node(cur->data);
            tail->next=n;
            n->prev=tail;
            tail=n;
            cur=cur->next;

        }
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

    LinkedList * ll = new LinkedList();
    int n,k;
    string str;
    cin >> n >> k;
    while(n--){
        cin >> str;
        ll->add(str);
    }
    ll->cyclicShift(k);
    ll->print();

    return 0;
}