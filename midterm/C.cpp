#include <iostream>
using namespace std;
//  done
struct Node {
public:
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = nullptr;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head = nullptr;
    int sz = 0;
  public:
 
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
        Node * node = new Node(x);
      // write your code here 
        if(head==NULL){
            head=node;
        }
        else{
            node->prev=head;
            head=node;
            Node * temp=head->prev;
            while(temp!=NULL){
                if(temp->value<=node->value){
                    node->ans=temp->value;
                    break;
                }
                temp=temp->prev;
            }
        }
        sz++;
        return node->ans;         
    }
 
};
 
int main() {
    Stack * st=new Stack();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << st->push(x) << " ";
    }
}