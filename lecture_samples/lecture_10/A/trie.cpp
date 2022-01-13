#include <iostream>

using namespace std;

const int N = 26;

class Node  {
    public:
    char value;
    Node *ch[N];
    int cnt; // считает сколько раз префиксы встречались,считая букву
    bool isEndOfWord;

    Node(char value) {
        this->value = value;
        for (int i = 0; i < N; i++) 
            this->ch[i] = NULL;
        this->isEndOfWord=false; // отмечает конец строки тем самым потом можем считать различные слова
        this->cnt = 1;
    }
};

class Trie {
    public:
    int distinct_string;
    int distinct_substring,cnt_pref;
    Node *root;
    Trie() {
        this->distinct_string=0;
        this->distinct_substring=0;
        this->cnt_pref=0;
        root = new Node('*');
    }

    void insert(string s) { // abcd
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->cnt++; //считаем сколько раз встречались буква тем самым считая сколько раз встретился префикс
            }
            else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
                this->distinct_substring++; //считает сколько различных подстрок есть в строке, нужно вторым фориком пробегаться для этого
                this->cnt_pref++; //чтобы считать сколько различных префиксов при каждом добавлении
                if (i == s.size() - 1){ 
                    //если новую букву добавляет и это последняя буква то отмечаем и увеличиваем счетчик различных строк
                    cur->isEndOfWord=true;
                    distinct_string++;
                }
            }
        } 
    }
};


int main() {
    Trie *trie = new Trie();
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
    }
    cout << trie->distinct_string << endl; 
    // 2-форик
    // считает различные подстроки данной строки
    // cin >> s;
    // for(int i=0;i<s.size();i++){
    //     string t=s.substr(i,s.size()-i);
    //     // cout << t << " ";
    //     for(int j=1;j<=t.size();j++){
    //         trie->insert(t.substr(0,j));
    //     }
    // }
    // cout << endl << trie->distinct_substring;
    return 0;
}
