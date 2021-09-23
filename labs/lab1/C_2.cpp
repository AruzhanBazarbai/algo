//61-task
#include <iostream>
#include <deque>
using namespace std;
//done
//Deque

int main(){
    deque<int> d;
    // deque<int>::iterator b_it=d.begin();
    // deque<int>::iterator e_it=d.
    string str;
    int x;


    while(cin>>str){
        if(str=="pop_front"){
            if(!d.empty()){
                cout << d.front() << endl;
                d.pop_front();

            }else cout << "error" << endl;
        }else if(str=="pop_back"){
            if(!d.empty()){
                cout << d.back() << endl;
                d.pop_back();

            }else cout << "error" << endl;

        }else if(str=="front"){
            if(!d.empty()){
                cout << d.front() << endl;

            }else cout << "error" << endl;
        }else if(str=="back"){
            if(!d.empty()){
                cout << d.back() << endl;

            }else cout << "error" << endl;
        }else if(str=="size") cout << d.size() << endl;
        else if(str=="clear"){
            d.clear();
            cout << "ok" << endl;
        }else if(str=="exit"){
            cout << "bye" << endl;
            return 0;
        }else if(str=="push_front"){
            cin >> x;
            d.push_front(x);
            cout << "ok" << endl;
        }else if(str=="push_back"){
            cin >> x;
            d.push_back(x);
            cout << "ok" << endl;
        }
    }
}