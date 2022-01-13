#include <iostream>

using namespace std;

const int N = 26;

class Node  {
    public:
    char value;
    Node *ch[N];
    long long cnt; // считает сколько раз префиксы встречались,считая букву
    bool isEndOfWord;

    Node(char value) {
        this->value = value;
        for (int i = 0; i < N; i++) 
            this->ch[i] = NULL;
        this->isEndOfWord=false; // отмечает конец строки тем самым потом можем считать различные слова
        this->cnt = 1;
    }
};

class Trie{
    public:
    long long  distinct_string;
    long long  distinct_substring,cnt_pref;
    Node *root;
    Trie(){
        this->distinct_string=0;
        this->distinct_substring=0;
        this->cnt_pref=0;
        root = new Node('*');
    }

    void insert(string s) { // abcd
        Node *cur = root;
        for (long long  i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->cnt++;
                if (i == s.size() - 1){ 
                    cur->isEndOfWord=true;
                    distinct_string++;
                }
            }
            else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
                if (i == s.size() - 1){ 
                    cur->isEndOfWord=true;
                    distinct_string++;
                }
                
            }
            
        } 
    }
    void del(string s){
        Node *cur = root;
        bool f=false;
        long long  res=distinct_string;
        for (long long  i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                if (i == s.size() - 1){ 
                    if(cur->isEndOfWord){
                        cur->isEndOfWord=false;
                        distinct_string--;
                    }
                    
                    for(int i=0;i<26;i++){
                        if(cur->ch[i]!=NULL){
                            f=true;
                            break;
                        }
                    }
                }
                
            }else break;
            
        } 
        if(f){
            if(res>distinct_string){
                Node * temp=root;
                long long  i=0;
                while(i<s.size()){
                    temp = temp->ch[s[i] - 'a'];
                    temp->cnt--;
                    i++;
                }
            }
        }else{
            Node * temp=root;
            temp->ch[s[0] - 'a'] = NULL;

        }


    }
    int find(string s){
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                if (i == s.size() - 1){ 
                    return cur->cnt;
                } 
            }else break;
            
        } 
    }
};


int main() {
    Trie *trie = new Trie();
    long long n;
    string s;
    char x;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> x >> s;
        if(x=='+'){
            trie->insert(s);
        }else if(x=='-'){
            trie->del(s);
        }else if(x=='?'){
            cout << trie->find(s) << endl;
        }
        
    }
    return 0;
}
