// Задача №112514.Список чисел
// Напишите программу, которая управляет списком чисел по командам, записанным в файл input.txt . Сначала список пустой. 
// Существует две команды: '+' – добавление числа в список, и '-' – удаление числа из списка. Попытка удалить число, которого нет в списке,
//  считается ошибкой.

// Входные данные
// В файле input.txt записаны строки с командами, последняя строка файла – пустая. Первый символ любой рабочей строки – это команда 
// ('+' или '-'), далее без пробела записывается число, которое добавляется или удаляется.

// Выходные данные
// В файл output.txt нужно вывести все числа, которые остались в списке, разделив их пробелами. Если в списке не осталось ни одного числа, 
// нужно вывести слово 'EMPTY'. В случае ошибки нужно вывести слово 'ERROR'.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// done
class Node{
public:
    int data;
    Node * prev;
    Node * next;

    Node(int data){
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
    bool error;

    LinkedList(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
        this->error=false;
    }

    void add(int data){
        Node * node=new Node(data);
        size++;
        if(head==NULL){
            head=tail=node;
            
        }else{
            node->prev=tail;
            tail->next=node;
            tail=node;
        }
    }
    void dl(int data){
        Node * temp=tail;
        bool k=true;
        if(size>0){
            size--;
            while(temp!=NULL){
                if(temp->data==data){
                    if(temp->prev!=NULL && temp->next!=NULL){
                        temp->prev->next=temp->next;
                        temp->next->prev=temp->prev;
                        // cout << "---1" << endl;
                        k=false;
                        delete temp;
                        break;
                    }else if(temp->prev==NULL && temp->next!=NULL){
                        head=temp->next;
                        temp->next->prev=NULL;
                        // cout << "---2" << endl;
                        k=false;
                        delete temp;
                        break;
                    }else if(temp->prev!=NULL && temp->next==NULL){
                        tail=temp->prev;
                        temp->prev->next=NULL;
                        // cout << "---3" << endl;
                        k=false;
                        delete temp;
                        break;
                    }else if(temp->prev==NULL && temp->next==NULL){
                        head=tail=NULL;
                        // cout << "---4" << endl;
                        k=false;
                        delete temp;
                        break;
                    }
                    
                }else{
                    temp=temp->prev;
                    // cout << "---5" << endl;
                }
            }
        }
        if(k) error=true;

    }


    void print(int q){
        freopen("output.txt","w",stdout);
        if(q==1) cout << "ERROR";
        else if(q==2){
            if(empty()){
                cout << "EMPTY";
            }else{
                vector<int> v;
                while(head!=NULL){
                    v.push_back(head->data);
                    // cout << head->data << " " ;
                    head=head->next;
                }
                sort(v.begin(),v.end());
                for(int i=0;i<v.size();i++){
                    cout << v[i] << " ";
                }
            }
        }
        fclose(stdout);
    }
    bool empty(){
        if(size==0) return true;
        return false;
    }
    

};

int main(){
    freopen("input.txt","r",stdin);
    
    string str;
    LinkedList ll;
    while(cin >> str){
        int res=0;
        char c=str[0];
        for(size_t i=1;i<str.size();i++){
            int x=(int)str[i]-'0';
            res=res*10+x;
        }
        // cout << res << "---" << endl;
        if(c=='+'){
            ll.add(res);
        }else if(c=='-'){
            ll.dl(res);
            if(ll.error){
                ll.print(1);
                return 0;
            }
        }
        
    }
    ll.print(2);

    return 0;
}