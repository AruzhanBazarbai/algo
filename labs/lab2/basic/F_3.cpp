/*

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
// 
class Node{
    public:
    int lvl;
    string data;
    Node * next, * prev;
    Node(int lvl,string data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
        this->lvl=lvl;
    }
};

class LinkedList{
    public:
    Node * head, * tail;
    bool ok;
    int sz;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->ok=true;
        this->sz=0;
    }
    void add(int lvl,string data){
        Node * node = new Node(lvl,data);
        
        // cout << sz << "------3" << endl;
        if(head == NULL){
            head = tail = node;
            sz++;
        }else if(lvl==1 && sz==1){
            head=node;
            head->next=tail;
            tail->prev=head;
            tail->lvl++;
            sz++;
        }else if(lvl<=sz){
            // cout << "-------2" << endl;
            Node *temp=find(lvl);
            // cout << temp->data << " " << temp->lvl << "--------1" << endl;
            if(temp==head){
                head->prev=node;
                node->next=head;
                head=node;
            }else{
                temp->prev->next=node;
                node->prev=temp->prev;
                temp->prev=node;
                node->next=temp;
                
            }
            while(temp!=NULL){
                temp->lvl++;
                temp=temp->next;
            }
            sz++;
                
        }
        else if(lvl-1==sz){
            tail->next=node;
            node->prev=tail;
            tail=node;
            sz++;
        }
        else{
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR";
            ok=false;
        }
        
        // print2();
    }

    Node * find(int lvl){
        Node * temp = head;
        while(temp != NULL){
            if(temp->lvl == lvl){
                return temp;
            }
            temp = temp->next;
        }   
    }

    void dl(int lvl){
        if(lvl>sz){
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR";
            ok=false;
        }
        else{
            Node * temp=find(lvl);
            if(temp->prev==NULL && temp->next==NULL){
                head=tail=NULL;
            }else if(temp->prev!=NULL && temp->next!=NULL){
                Node * t=temp->next;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp=NULL;
                while(t!=NULL){
                    t->lvl--;
                    t=t->next;
                }
                
            }else if(temp->prev!=NULL && temp->next==NULL){
                tail=temp->prev;
                tail->next=NULL;
                temp=NULL;
            }else if(temp->prev==NULL && temp->next!=NULL){
                head=head->next;
                head->prev=NULL;
                temp=head;
                while(temp!=NULL){
                    temp->lvl--;
                    temp=temp->next;
                }
            }
            // delete temp;
            sz--;
        }
        // print2();
    }

    void replacell(int lvl, string data){
        if(lvl>sz){
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR";
            ok=false;
        }
        else{
            Node * temp=find(lvl);
            temp->data=data;
        }
        // print2();
    }




    void print(){
        ofstream outF;
        outF.open("output.txt");
        // freopen("output.txt","w",stdout);
        
        if(head==NULL) outF << "EMPTY" << endl;
        else{
            Node * temp = head;
            while(temp != NULL){
                outF << temp->data << endl;
                temp = temp->next;
            }
        }
        // fclose(stdout);
    }
    void print2(){
        Node * temp = head;
        while(temp != NULL){
            cout << temp->data << " " <<temp->lvl << endl;
            temp = temp->next;
        }
        cout << "--------" << endl;
    }

};

int main(){
    ifstream inF;
    inF.open("input.txt");
    LinkedList * ll=new LinkedList();
    // freopen("input.txt","r",stdin);
    string s,y;
    while(getline(inF,s)){
        char c=s[0];
        int lvl=(int)s[1]-'0';
        
        if(c=='+'){
            string res="";
            for(size_t i=3;i<s.size();i++){
                res+=s[i];
            }
            ll->add(lvl,res);
        }else if(c=='-'){
            ll->dl(lvl);
            
        }else if(c=='*'){
            string res="";
            for(size_t i=3;i<s.size();i++){
                res+=s[i];
            }
            ll->replacell(lvl,res);
        }
        if(ll->ok==false){
            // ll->print(1);
            return 0;
        }
    }
    ll->print();

    return 0;
}