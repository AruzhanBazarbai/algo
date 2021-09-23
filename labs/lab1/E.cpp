//50 task
// Игра в пьяницу
#include <iostream>
#include <deque>
using namespace std;
//done
int main(){
    deque<int> d1,d2;
    long long n=0;
    int x;
    for(int i=0;i<5;i++){
        cin >> x;
        d1.push_back(x);
    }
    for(int i=0;i<5;i++){
        cin >> x;
        d2.push_back(x);
    }

    while(!d1.empty() && !d2.empty()){
        if((d1.front()==0 || d2.front()==0)&&(d2.front()==9 || d1.front()==9)){
            if(d1.front()>d2.front()){ //d1=9 d2=0
                d2.push_back(d1.front());
                d1.pop_front();
                d2.push_back(d2.front());
                d2.pop_front();
            }else{ //d1=0 d2=9
                d1.push_back(d1.front());
                d1.pop_front();
                d1.push_back(d2.front());
                d2.pop_front();

            }
        }else{
            if(d1.front()>d2.front()){ //d1=8 d2=5
                d1.push_back(d1.front());
                d1.pop_front();
                d1.push_back(d2.front());
                d2.pop_front();
            }else{ //d1=5 d2=8
                d2.push_back(d1.front());
                d1.pop_front();
                d2.push_back(d2.front());
                d2.pop_front();

            }
        }
        n++;
        if(n>1000000){
            cout << "botva";
            return 0;
        }
    }
    if(d1.empty()) cout << "second" << " " << n << endl;
    else cout << "first" << " " << n << endl;

}