//52-task
// Постфиксная запись
#include <iostream>
#include <stack>
using namespace std;
//done
int main(){
    stack<int> st;
    int x=0,y=0;
    char c;
    while(cin>>c){
        if(c>='0' && c<='9'){
            x=int(c)-'0';
            st.push(x);
        }else if(c=='+'){
            if(st.size()>=2){
                x=0;
                y=0;
                x+=st.top();
                st.pop();
                y+=st.top();
                st.pop();
                st.push(y+x);
                
            }
        }else if(c=='-'){
            if(st.size()>=2){
                x=0;
                y=0;
                x+=st.top();
                st.pop();
                y+=st.top();
                st.pop();
                st.push(y-x);
                
            }
        }else if(c=='*'){
            if(st.size()>=2){
                x=0;
                y=0;
                x+=st.top();
                st.pop();
                y+=st.top();
                st.pop();
                st.push(y*x);
                
            }
        }
    }
    cout << st.top() << endl;
}