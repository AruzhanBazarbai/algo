#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *prev;

  Node(int data){
    this->data = data;
    this->prev = NULL;
  }
};

class deque{
  private:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
  public:
  void push_back(int data){
    Node *node = new Node(data);
    if (sz == 0) head = node;
    else tail -> prev = node;
    tail = node;
    sz++;
    cout << "ok" << endl;
  }

  void pop_back(){
    tail = tail->prev;
    sz--;
  }

  void push_front(int data){
    Node *node = new Node(data);
    if (sz == 0) head = node;
    else head -> prev = node;
    head = node;
    sz++;
    cout << "ok" << endl;
  }

  void pop_front(){
    if(sz==0) cout << "error" << endl;
    else{
        cout << head->data << endl;
        head = head->prev;
        sz--;
    }
  }

  void clear(){
    sz=0;
    tail=NULL;
    head=NULL;
    cout << "ok" << endl;
  }

  void size(){
    cout << sz << endl;
  }

  void back(){
    if(sz==0) cout << "error" << endl;
    else cout << tail->data << endl;
  }

  void front(){
    if(sz==0) cout << "error" << endl;
    else cout << head->data << endl;
  }

};

int main(){
    deque *dq=new deque();
    string str;

    while (cin >> str){
        if (str=="push_back"){
            int x;
            cin >> x;
            dq->push_back(x);
        }
        else if (str=="pop_back") dq->pop_back();
        else if (str=="push_front"){
            int x;
            cin >> x;
            dq->push_front(x);
        }
        else if (str=="pop_front") dq->pop_front();
        else if (str=="size") dq->size();
        else if (str=="back") dq->back();
        else if(str=="front") dq->front();
        else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else if(str=="clear") dq->clear();
    }
}