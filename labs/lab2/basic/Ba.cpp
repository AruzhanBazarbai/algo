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
                if (cur->next == NULL) {
                    cur->next = node;
                    node->prev = cur;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    void sort_cnt() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            while(nx) {
                if (nx->cnt > cur->cnt) {
                    int tmp = cur->cnt;
                    cur->cnt = nx->cnt;
                    nx->cnt = tmp;
                    string str = cur->val;
                    cur->val = nx->val;
                    nx->val = str;
                }
                nx = nx->next;
            }
            cur = cur->next;
        }
    }
    void sort_value() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            while (nx) {
                if (cur->cnt == nx->cnt and cur->val > nx->val) {
                    int tmp = cur->cnt;
                    cur->cnt = nx->cnt;
                    nx->cnt = tmp;
                    string str = cur->val;
                    cur->val = nx->val;
                    nx->val = str;
                }
                nx = nx->next;
            }
            cur = cur->next;
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
    linked.sort_cnt();
    linked.sort_value();
    linked.console_output();
    return 0;
}