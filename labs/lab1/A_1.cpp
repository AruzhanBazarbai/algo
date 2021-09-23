//55-task
#include <iostream>
using namespace std;
//done with code Baisakov
//stack
struct st{
    long long a[1000000];
    long long topindex;

    st(){
        topindex=-1;
    }

    long long back(){
        if(topindex==-1) return -1;
        return a[topindex];
    }

    void push(long long x){
        topindex++;
        a[topindex]=x;
    }

    void pop(){
        if(topindex!=-1){
            cout << a[topindex] << endl;
            topindex--;
        }else cout << "error" << endl;
    }

    void clear(){
        topindex=-1;   
    }
};

int main(){
    string str, res="";
    long long x;
    st s;
    
    while(cin >> str){
        if(str=="pop"){
            s.pop();

        }else if(str=="back"){
            if(s.back()!=-1) cout << s.back() << endl;
            else cout << "error" << endl;

        }else if(str=="size"){
            cout << s.topindex+1 << endl;
            
        }else if(str=="clear"){
            s.clear();
            cout << "ok" << endl;

        }else if(str=="exit"){
            cout << "bye" << endl;
            return 0;

        }else{
            cin >> x;
            s.push(x);
            cout << "ok" << endl;
        }
    }
}