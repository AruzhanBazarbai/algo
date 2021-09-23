#include<iostream>

using namespace std;
//code of Abduvali

class MyQueue{
private:
    int maxSize;
    int front;
    int back;
    int *arr;
    int n;
public:

    MyQueue(int capacity){
        maxSize = capacity;
        arr = new int[maxSize];
        front = 0;
        back = 0;
        n = 0;
    }

    // O(1)
    void insert(int value){
        if (back == maxSize - 1) return;
        arr[back] = value;
        back++;
        n++;
    }

    // O(1)
    int pop() {
        if (front == maxSize - 1) return -1;
        int temp = arr[front];
        front++;
        n--;
        return temp;
    }
    // O(1)
    bool isEmpty(){return n == 0;}

    // O(1)
    int size() { return n; }
};

class Node{
public:
    int data;
    Node *next, *prev;
    Node(int val){
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList{
public:
    Node *front, *tail;
    LinkedList(){
        front = nullptr;
        tail = nullptr;
    }

    void push_back(int data){
        Node *node = new Node(data);
        if (tail == nullptr){
            tail = node;
            front = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }


    void push_front(int data){
        Node *node = new Node(data);
        if (front == nullptr){
            tail = node;
            front = node;
        }
        else{
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back(){
        if (tail != nullptr){
            tail = tail->prev;
            if (tail == nullptr){
                front = nullptr;
            }else{
                tail->next = nullptr;
            }
        }
    }

    void pop_front(){
        if (front != nullptr){
            front = front->next;
            if (front == nullptr){
                tail = nullptr;
            }else{
                front->prev = nullptr;
            }
        }
    }

    void insert(Node *a, int data){
        if (a == tail){
            push_back(data);
            return;
        }
        Node *b = a->next;
        Node *node = new Node(data);
        a->next = node;
        node->prev = a;
        b->prev = node;
        node->next = b;
    }

    Node* find_el(int data){
        Node *node = new Node(data);
        while(node != nullptr){ // O(n)
            if (node->data == data){
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }

    void delete_el(Node *node){
        if (node == tail) pop_back();
        else if (node == front) pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print(){
        Node *node = front;
        while(node != nullptr){
            cout << node->data << '\n';
            node = node->next;
        }
    }

};


int main(){
    MyQueue *myQueue = new MyQueue(3);
    myQueue->insert(1);
    myQueue->insert(1);
    myQueue->pop();
    cout << "QUEUE\n";
    cout << myQueue->size() << endl;
    cout << "LINKED LIST\n";
    // [1,2,3] // [1,2,3] [0,0]
    // [1 -> 3]
    LinkedList *linkedList = new LinkedList();
    linkedList->insert(linkedList->front, 1);
    linkedList->insert(linkedList->front, 2);
    linkedList->insert(linkedList->front, 3);
    Node *node = linkedList->find_el(2);
    cout << node->data;
    //linkedList->delete_el(node);
    linkedList->print();
    return 0;
}