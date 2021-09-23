#include <iostream>
#include <queue>
using namespace std;
//done
// Списки по классам

int main(){
    queue<string> q_9;
    queue<string> q_10;
    queue<string> q_11;

    int x;
    string str;

    while(cin >> x){
        if(x==9){
            cin >> str;
            q_9.push(str);
        }else if(x==10){
            cin >> str;
            q_10.push(str);
        }else{
            cin >> str;
            q_11.push(str);
        }
    }

    while(!q_9.empty()){
        cout << 9 << " " << q_9.front() << endl;
        q_9.pop();
    }
    while(!q_10.empty()){
        cout << 10 << " " << q_10.front() << endl;
        q_10.pop();
    }
    while(!q_11.empty()){
        cout << 11 << " " << q_11.front() << endl;
        q_11.pop();
    }
    return 0;

}