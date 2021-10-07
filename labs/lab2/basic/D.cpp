/*
Задача №112513. Словарь для файла с пунктуацией
Напишите программу, которая строит алфавитно-частотный словарь для файла input.txt , в котором записаны слова, состоящие из букв 
латинского алфавита (заглавных и строчных) и знаков препинания (.,:;!?). 
Заглавные и строчные буквы не различаются. Знаки препинания нужно игнорировать. Слова необходимо отсортировать в порядке убывания 
частоты (сначала слова, которые встретились чаще всего). Слова с одинаковой частотой должны располагаться в алфавитном порядке.

Входные данные
Входной файл содержит неизвестное количество строк, в каждой из которых записаны слова, состоящее из букв латинского алфавита 
(заглавных и строчных) и знаков препинания (.,:;!?). В одной строке могут быть записаны несколько слов, разделенных произвольным 
количеством пробелов. Последняя строка файла – пустая. Пробелы могут быть также в начале и в конце строк. После знака препинания 
обязательно стоит пробел.

Выходные данные
Программа должна вывести в файл output.txt все различные слова, которые встретились в исходном файле, по одному слову в строке. 
После каждого слова через пробел записывается количество таких слов в файле. Слова должны быть отсортированы по убыванию частоты 
(сначала слова, которые встретились чаще всего).
*/
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
        if(head==NULL){
            head=tail=node;
            
        }else if(!find(data)){
            node->prev=tail;
            tail->next=node;
            tail=node;
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
    void sort_cnt(){
        Node * cur=head;
        while(cur){
            Node * temp=cur->next;
            while(temp){
                if((cur->cnt < temp->cnt) || (cur->cnt==temp->cnt && cur->data>temp->data)){
                    int x=cur->cnt;
                    cur->cnt=temp->cnt;
                    temp->cnt=x;
                    string val=cur->data;
                    cur->data=temp->data;
                    temp->data=val;                    
                }
                
                temp=temp->next;
            }
            cur=cur->next;

        }

    }

    void print(){
        freopen("output.txt","w",stdout);
        while(head!=NULL){
            
            cout << head->data << " " << head->cnt << endl;
            head=head->next;
        }
        fclose(stdout);
    }
    

};

int main(){
    freopen("input.txt","r",stdin);
    
    string str;
    LinkedList ll;
    while(cin >> str){
        string res="";
        for(int i=0;i<str.size();i++){
            if(str[i]!='.' && str[i]!=',' && str[i]!=':' && str[i]!=';' && str[i]!='!' && str[i]!='?') res+=tolower(str[i]);
        }
        // cout << res << "---" << endl;
        ll.add(res);
        
    }
    ll.sort_cnt();
    ll.print();

    return 0;
}