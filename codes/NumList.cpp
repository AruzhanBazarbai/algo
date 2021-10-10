/*
Задача №112514. Список чисел
Напишите программу, которая управляет списком чисел по командам, записанным в файл input.txt . Сначала список пустой. 
Существует две команды: '+' – добавление числа в список, и '-' – удаление числа из списка. Попытка удалить число, которого нет в списке, 
считается ошибкой.

Входные данные
В файле input.txt записаны строки с командами, последняя строка файла – пустая. Первый символ любой рабочей строки – это команда ('+' или '-'), 
далее без пробела записывается число, которое добавляется или удаляется.

Выходные данные
В файл output.txt нужно вывести все числа, которые остались в списке, разделив их пробелами. Если в списке не осталось ни одного числа, 
нужно вывести слово 'EMPTY'. В случае ошибки нужно вывести слово 'ERROR'.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Node{
    public:
    int data;
    Node * next, * prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LinkedList{
    public:
    Node * head, * tail;
    bool ok;
    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        ok=true;
    }
    void add(int data){
        Node * node = new Node(data);
        if(head == NULL){
            head = tail = node;
        }else{
            node->prev=tail;
            tail->next=node;
            tail=node;
           
        }
    }

    Node * find(int data){
        Node * temp = head;
        Node * res=NULL;
        while(temp != NULL){
            if(temp->data == data){
                res=temp;
                return res;
            }
            temp = temp->next;
        }   
        return res;
    }

    void dl(int data){
        Node * temp=find(data);
        if(temp==NULL || head==NULL) ok=false;
        else{
            if(temp->prev==NULL && temp->next==NULL){
                head=tail=NULL;
            }else if(temp->prev!=NULL && temp->next!=NULL){
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }else if(temp->prev!=NULL && temp->next==NULL){
                tail=temp->prev;
                tail->next=NULL;
                temp->prev->next=NULL;
            }else if(temp->prev==NULL && temp->next!=NULL){
                temp->next->prev=NULL;
                head=temp->next;
            }
            delete temp;
        }
    }


    void print(int q){
        freopen("output.txt","w",stdout);
        if(q==1){
            cout << "ERROR";
        }
        else{
            if(head==NULL) cout << "EMPTY";
            else{
                vector<int> v;
                Node * temp = head;
                while(temp != NULL){
                    v.push_back(temp->data);
                    temp = temp->next;
                }
                sort(v.begin(),v.end());
                for(auto x : v){
                    cout << x << " ";
                }
            }
        }
        fclose(stdout);
    }

};

int main(){
    LinkedList * ll=new LinkedList();
    freopen("input.txt","r",stdin);
    string s;
    while(cin>>s){
        int res=0;
        char c=s[0];
        for(size_t i=1;i<s.size();i++){
            int x=(int)s[i]-'0';
            res=res*10+x;
        }
        if(c=='+'){
            ll->add(res);
        }else if(c=='-'){
            ll->dl(res);
            if(ll->ok==false){
                ll->print(1);
                return 0;
            }
        }
    }
    ll->print(2);

    return 0;
}