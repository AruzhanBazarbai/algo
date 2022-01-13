// /*
// C. Система регистрации
// В скором времени в Берляндии откроется новая почтовая служба "Берляндеск". 
// Администрация сайта хочет запустить свой проект как можно быстрее, поэтому они попросили Вас о помощи. 
// Вам предлагается реализовать прототип системы регистрации сайта.

// Система должна работать по следующему принципу. Каждый раз, когда новый пользователь хочет зарегистрироваться, 
// он посылает системе запрос name со своим именем. Если данное имя не содержится в базе данных системы, то оно заносится туда и 
// пользователю возвращается ответ OK, подтверждающий успешную регистрацию. Если же на сайте уже присутствует пользователь с именем name, 
// то система формирует новое имя и выдает его пользователю в качестве подсказки, при этом подсказка также добавляется в базу данных. 
// Новое имя формируется по следующему правилу. К name последовательно приписываются числа, начиная с единицы (name1, name2, ...), 
// и среди них находят такое наименьшее i, что namei не содержится в базе данных сайта.

// Входные данные
// В первой строке входных данных задано число n (1 ≤ n ≤ 105). Следующие n строк содержат запросы к системе. 
// Каждый запрос представляет собой непустую строку длиной не более 32 символов, состоящую только из строчных букв латинского алфавита.

// Выходные данные
// В выходных данных должно содержаться n строк — ответы системы на запросы: ОК в случае успешной регистрации, или подсказку с новым именем, 
// если запрашиваемое уже занято.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
class Node{
    public:
    long long key;
    int value;
    Node *right, *left;
    Node(long long key,int value){
        this->key=key;
        this->value=value;
        this->left=NULL;
        this->right=NULL;
    }
};
class MyHashMap {
public:
    Node * node,*root; 
    int ans;
    MyHashMap() {
        this->node=NULL;
        this->root=NULL;
    }
    
    Node * put(long long key,Node * node) {
        if(node==NULL){
            node=new Node(key,1);
            ans=0;
            return node;
        }
        if(key<node->key) node->left=put(key,node->left);
        else if(key>node->key) node->right=put(key,node->right);
        else if(key==node->key){
            node->value++;
            ans=node->value;
        }
        return node;
        
    }
    
    int get(long long key) {
        Node * temp=root;
        while(temp!=NULL){
            if(key==temp->key){
                return temp->value;
            }
        }
        return -1;
    }
};
int main(){
    MyHashMap * hash=new MyHashMap();
    long long n; 
    cin >> n;
    long long p_pow[32];
    p_pow[0]=1;
    for(int i=1;i<32;i++){
        p_pow[i]=p_pow[i-1]*31;
    }
    while(n--){
        string s;
        cin >> s;
        long long h=0;
        for(int i=0;i<s.size();i++){
            h+=(s[i]-'a'+1)*p_pow[i];
        }
        hash->root=hash->put(h,hash->root);
        if(hash->ans==0) cout << "OK" << endl;
        else cout << s << hash->ans-1 << endl;

    }
    return 0;
}