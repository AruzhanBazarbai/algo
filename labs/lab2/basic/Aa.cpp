#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Node 
{
    string val;
    int cnt;
    Node* prev;
    Node* next;
    Node (string x) {
        this->val = x;
        this->prev = NULL;
        this->next = NULL;
        this->cnt = 1;
    }
};

struct ll
{
private:
    Node* head = NULL;
    Node* tail = NULL;
public:
    void push(string x) {
        Node* node = new Node(x);
        if (head == NULL) {
            head = tail = node;
        }
        else {
            Node* cur = head;
            while (cur) {
                if (cur->val == node->val) {
                    cur->cnt++;
                    break;
                }
                if (cur->val > node->val) {
                    if (cur->prev != NULL) {
                        cur->prev->next = node;
                        node->prev = cur->prev;
                        node->next = cur;
                        cur->prev = node;
                    }
                    else {
                        head = node;
                        node->next = cur;
                        cur->prev = node;
                    }
                    break;
                }
                if (cur->next == NULL) {
                    cur->next = node;
                    node->prev = cur;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    void console_output() {
        Node* cur = head;
        while(cur) {
            fout << cur->val << ' ' << cur->cnt << endl;
            cur = cur->next;
        }
    }
};

int main() {
    ll linked;
    while (!fin.eof()) {
        string s;
        getline(fin, s);
        if (s == "") continue;
        linked.push(s);
    }
    linked.console_output();
    return 0;
}