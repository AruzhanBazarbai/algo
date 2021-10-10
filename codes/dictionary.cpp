/*

Задача №112510. Алфавитно-частотный словарь
Напишите программу, которая строит алфавитно-частотный словарь для файла input.txt , в котором в столбик записаны слова, состоящие только из строчных букв латинского алфавита.

Входные данные
Входной файл содержит неизвестное количество строк, в каждой из которых записано слово, состоящее только из строчных букв латинского алфавита. Последняя строка файла – пустая.

Выходные данные
Программа должна вывести в файл output.txt в алфавитном порядке все различные слова, которые встретились в исходном файле, по одному слову в строке. После каждого слова через пробел записывается количество таких слов в файле.
*/
#include <iostream>
using namespace std;
// done
class Node{
    public:
    string data;
    int sz;
    Node * next, * prev;
    Node(string data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
        this->sz=1;
    }
};

class LinkedList{
    public:
    Node * head, * tail;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
    }
    void add(string data){
        Node * node = new Node(data);
        if(head == NULL){
            head = tail = node;
        }else if(!find(data)){
            Node * temp=head;
            while(temp!=NULL){
                if(temp->data > data){
                    break;
                }
                temp=temp->next;
            } 
            if(temp==NULL){
                node->prev=tail;
                tail->next=node;
                tail=node;
            }else if(temp->prev==NULL){
                head->prev=node;
                node->next=head;
                head=node;
            }else if(temp->prev!=NULL){
                temp->prev->next=node;
                node->prev=temp->prev;
                temp->prev=node;
                node->next=temp;
            }
        }
    }

    bool find(string data){
        Node * temp = head;
        Node * result = NULL;
        while(temp != NULL){
            if(temp->data == data){
                temp->sz++;
                return true;
            }
            temp = temp->next;
        }   
        return false;
    }


    void print(){
        Node * temp = head;
        freopen("output.txt","w",stdout);
        while(temp != NULL){
            cout << temp->data << " " << temp->sz << endl;
            temp = temp->next;
        }
        fclose(stdout);
    }

};

int main(){
    LinkedList * ll=new LinkedList();
    freopen("input.txt","r",stdin);
    string s;
    while(cin>>s){
        ll->add(s);
    }
    ll->print();

    return 0;
}