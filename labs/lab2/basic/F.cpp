#include <iostream>
using namespace std;
// 
class Node{
public:
    string data;
    int ind;
    Node * prev;
    Node * next;

    Node(int ind,string data){
        this->ind=ind;
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

};

class LinkedList{
public:
    Node * head;
    Node * tail;
    int size;
    bool error=false;

    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }

    void add(int x,string data){
        Node * node=new Node(x,data);
        
        if(head==NULL){
            head=tail=node;
            size++;
                
        }else if(x==1  && size>=1){
            Node * temp=head;
            head->prev=node;
            node->next=head;
            head=node;
            size++;
            while(temp!=NULL){
                temp->ind++;
                temp=temp->next;
            }
            
        }else if(x==size+1){
            tail->next=node;
            node->prev=tail;
            tail=node;
            size++;
        }else if(x<=size){
            Node * temp=head;
            while(temp->ind!=x){
                temp=temp->next;
            }
            Node * cur=temp;
            if(temp->prev==NULL){
                head->prev=node;
                node->next=head;
                head=node;
                size++;
                // cout << "---2" << endl;
                    // k=false;
            }
            else{
                temp->prev->next=node;
                node->prev=temp->prev;
                node->next=temp; 
                temp->prev=node;
                size++;
                    // cout << "---1" << endl;
                    // k=false;
            }
            while(cur!=NULL){
                cur->ind++;
                cur=cur->next;
            }
            
        }else error=true;
    }
    void dl(int x){
        if(x>size || size==0) error=true;
        else{
            Node * temp=head;
            while(temp->ind!=x){
                temp=temp->next;
            }
            if(temp->prev!=NULL && temp->next!=NULL){
                Node * a=temp->next;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                while(a!=NULL){
                    a->ind--;
                    a=a->next;
                }
            }else if(temp->prev==NULL && temp->next!=NULL){
                head=head->next;
                // head->next=temp->next->next;
                head->prev=NULL;
                Node * a=head;
                while(a!=NULL){
                    a->ind--;
                    a=a->next;
                }
            }else if(temp->prev!=NULL && temp->next==NULL){
                tail=tail->prev;
                tail->next=NULL;
                
            }else if(temp->prev==NULL && temp->next==NULL){
                head=tail=NULL;
                size=0;
            } 
            
            if(size>0) size--;           
        }

    }
    void replace(int x,string data){
        if(x>size || size==0) error=true;
        else{
            Node * temp=head;
            while(temp->ind!=x){
                temp=temp->next;
            }
            temp->data=data;
        }

    }

    void print(int q){
        freopen("output.txt","w",stdout);
        if(q==1) cout << "ERROR";
        else if(q==2){
            if(size==0){
                cout << "EMPTY";
            }else{
                while(head!=NULL){
                    cout << head->data << endl ;
                    head=head->next;
                }
            }
        }
        fclose(stdout);
    }
    bool empty(){
        if(size==0 ) return true;
        return false;
    }
    

};

int main(){
    freopen("input.txt","r",stdin);
    
    string str;
    LinkedList * ll=new LinkedList();
    while(getline(cin,str)){
        string res="";
        char c=str[0];
        int x=(int)str[1]-'0';
        for(size_t i=3;i<str.size();i++){
            res+=str[i];
        }
        if(c=='+') ll->add(x,res);
        else if(c=='-') ll->dl(x);
        else if(c=='*') ll->replace(x,res);
            
        if(ll->error){
            ll->print(1);
            return 0;

        }
        
    }
    ll->print(2);

    return 0;
}