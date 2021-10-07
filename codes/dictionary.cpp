// Задача №112510. Алфавитно-частотный словарь
// Напишите программу, которая строит алфавитно-частотный словарь для файла input.txt , 
// в котором в столбик записаны слова, состоящие только из строчных букв латинского алфавита.

// Входные данные
// Входной файл содержит неизвестное количество строк, в каждой из которых записано слово, 
// состоящее только из строчных букв латинского алфавита. Последняя строка файла – пустая.

// Выходные данные
// Программа должна вывести в файл output.txt в алфавитном порядке все различные слова, 
// которые встретились в исходном файле, по одному слову в строке. После каждого слова через пробел записывается количество таких слов 
// в файле.

#include <iostream>
using namespace std;
// done
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
        Node * cur=tail;
        if(head==NULL){
            head=tail=node;
            
        }else if(!find(data)){
            while(cur!=NULL){
                if(cur->data < node->data){
                    if(tail->data < node->data){
                        tail->next=node;
                        node->prev=tail;
                        tail=node;
                        break;
                    }else{
                        Node * temp=cur->next;
                        cur->next=node;
                        node->prev=cur;
                        temp->prev=node;
                        node->next=temp;
                        break;
                    }

                }else if(cur->data>node->data && cur->prev==NULL){
                    node->next=cur;
                    cur->prev=node;
                    head=node;
                    break;
                }
                cur=cur->prev;
            }
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
    void print(){
        FILE * f=freopen("output.txt","w",stdout);
        while(head!=NULL){
            
            cout << head->data << " " << head->cnt << endl;
            head=head->next;
        }
        fclose(stdout);
    }
    

};

int main(){
    int i=0;
    freopen("input.txt","r",stdin);
    
    string str;
    LinkedList ll;
    while(getline(cin,str)){
        ll.add(str);
        i++;
    }
    ll.print();

    return 0;
}