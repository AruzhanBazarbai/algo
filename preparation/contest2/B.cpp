// /*
// Problem B. Age supremacy
// In an unnamed state, the ruler is chosen by the right of age. The most adult person in the country will
// sit on the throne. You are given the dates of birth of people, output the order of their government.
// Input
// The first line includes a single number n (1 ≤ n ≤ 105
// ). The next n lines contain dates of birth of people
// in the country.
// Output
// Print the answer.
// */
#include <iostream>
#include <string>
using namespace std;
// done
class Node{
    public:
    int d,m,y;
    Node * next, * prev;
    Node(int m,int d,int y){
        this->d=d;
        this->m=m;
        this->y=y;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LinkedList{
    public:
    Node * head, * tail;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }
    void add(int m,int d,int y){
        Node * node = new Node(m,d,y);
        if(head == NULL){
            head = tail = node;
        }else{
            tail->next=node;
            node->prev=tail;
            tail=node;

        }
    }
    void sort(){
        Node * temp=head;
        Node * cur=head;
        while(cur!=NULL){
            temp=cur->next;
            while(temp!=NULL){
                if((cur->y > temp->y) || (cur->y==temp->y && cur->m < temp->m) || (cur->y==temp->y && cur->m == temp->m && cur->d < temp->d)){
                    int x1=cur->d,x2=cur->m,x3=cur->y;
                    cur->d=temp->d;
                    cur->m=temp->m;
                    cur->y=temp->y;
                    temp->d=x1;
                    temp->m=x2;
                    temp->y=x3;
                }
                temp=temp->next;
            }
            cur=cur->next;
        }

    }


    void print(){
        Node * temp = head;
        while(temp != NULL){
            cout << temp->m << " " << temp->d << " " << temp->y << endl;
            temp = temp->next;
        }
    }

};

int main(){
    LinkedList * ll=new LinkedList();
    string s,d,m,y;
    
    // cin >> s >> x;
    
    // getline(cin,x);
    int n;
    cin >> n;
    while(n--){
        int d1=0,m1=0,y1=0;
        cin >> m >> d >> y;
        // m=s.substr(0,2);
        // d=s.substr(3,2);
        // y=s.substr(6,4);
        for(char x:d){
            d1=d1*10+((int)x-'0');
        }
        for(char x:m){
            m1=m1*10+((int)x-'0');
        }
        for(char x:y){
            y1=y1*10+((int)x-'0');
        }
        // cout << d1 << " " << m1 << " " << y1 << endl;
        ll->add(m1,d1,y1);
    }
    ll->sort();
    ll->print();

    return 0;
}