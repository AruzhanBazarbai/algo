#include <iostream>
using namespace std;

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
            sz++;
        }
        else{
            node->prev=head;
            head=node;
            sz++;
        }
        
        return ans(x);         
    }
    int ans(int x){
        if(sz>0){
            Node * cur=head;
            while(cur->prev!=NULL){
                if(cur->prev->value<=x){
                    head->ans=cur->prev->value;
                    break;
                }
                cur=cur->prev;
            }
        }
        return head->ans;
    }
 
}st;
 
int main() {
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << st.push(x) << " ";
    }
}