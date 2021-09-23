//51 task
// Правильная скобочная последовательность
#include <iostream>
#include <stack>
using namespace std;
//done 
int main(){
    stack<char> st;
    string str;
    bool k=true;

    cin >> str;
    for(long unsigned int i=0;i<str.size();i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{') st.push(str[i]);
        else{
            if(st.empty()){
                k=false;
                break;
            }else{
                if(str[i]==')'){
                    if(st.top()=='(') st.pop();
                    else{
                        k=false;
                        break;
                    }
                }else if(str[i]==']'){
                    if(st.top()=='[') st.pop();
                    else{
                        k=false;
                        break;
                    }
                }else if(str[i]=='}'){
                    if(st.top()=='{') st.pop();
                    else{
                        k=false;
                        break;
                    }
                }
            }
        }
    }

    if(k && st.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
}