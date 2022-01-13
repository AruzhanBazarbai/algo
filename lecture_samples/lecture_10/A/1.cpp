#include <iostream>
using namespace std;
const int N=26;
class Node{
    public:
    char value;
    int cnt;
    Node * ch[26];
    Node(char value){
        this->value=value;
        for(int i=0;i<N;i++){
            this->ch[i]=NULL;
        }
        this->cnt=1;
    }
};
class Trie{
    public:
    Node * root;
    int cnt=0;
    Trie(){
        this->cnt=0;
        root=new Node('*');
    }
    void insert(string s){
        Node * cur=root;
        for(int i=0;i<s.size();i++){
            if(cur->ch[s[i]-'a']!=NULL){
                cur=cur->ch[s[i]-'a'];
                cur->cnt++;//считаем сколько раз встречались буква тем самым считая сколько раз встретился префикс
            }else{
                Node * node=new Node(s[i]);
                cur->ch[s[i]-'a']=node;
                cur=node;
                cnt++;
            }
        }
    }
};
int main(){
    Trie *trie=new Trie();
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        trie->insert(s);
    }
    cout << trie->cnt << endl; //количество различных префиксов

    return 0;
}