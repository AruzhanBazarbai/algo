/*
Задача №112511. Cловарь по частотам
Напишите программу, которая строит алфавитно-частотный словарь для файла input.txt , в котором в столбик записаны слова, 
состоящие только из строчных букв латинского алфавита. Слова нужно отсортировать в порядке убывания частоты (сначала слова, 
которые встретились чаще всего). Слова с одинаковой частотой должны располагаться в алфавитном порядке.

Входные данные
Входной файл содержит неизвестное количество строк, в каждой из которых записано слово, состоящее только из строчных букв латинского алфавита. 
Последняя строка файла – пустая.

Выходные данные
Программа должна вывести в файл output.txt все различные слова, которые встретились исходном файле, по одному слову в строке. 
После каждого слова через пробел записывается количество таких слов в файле. Слова должны быть отсортированы по убыванию частоты (сначала слова, 
которые встретились чаще всего). Слова с одинаковой частотой должны располагаться в алфавитном порядке.
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
            node->prev=tail;
            tail->next=node;
            tail=node;
           
        }
    }

    bool find(string data){
        Node * temp = head;
        while(temp != NULL){
            if(temp->data == data){
                temp->sz++;
                return true;
            }
            temp = temp->next;
        }   
        return false;
    }
    void sortLL(){
        Node * temp=tail;
        Node * cur=tail;
        while(cur!=NULL){
            temp=cur->prev;
            while(temp!=NULL){
                if(cur->sz>temp->sz || (cur->sz==temp->sz && temp->data > cur->data)){
                    string s=cur->data;
                    int x=cur->sz;
                    cur->data=temp->data;
                    cur->sz=temp->sz;
                    temp->data=s;
                    temp->sz=x;
                }
                temp=temp->prev;
            }
            cur=cur->prev;
        }
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
    ll->sortLL();
    ll->print();

    return 0;
}