//112984 task
// Гоблины и шаманы
#include <iostream>
#include <deque>
using namespace std;
//done
int main(){
    long long n,x;
    cin >> n;
    char c;
    deque<long long> d1;
    deque<long long> d2;

    while(n>0){
        cin >> c;
        if(c=='+'){        
            cin >> x;
            d2.push_back(x);
        }else if(c=='*'){
            cin >> x;
            if(d1.size()==d2.size()) d1.push_back(x);
            else if(d1.size()>d2.size()) d2.push_front(x);
            else d1.push_back(x);

        }else{
            cout << d1.front() << endl;
            d1.pop_front();
        }

        while(d2.size()>d1.size()){
            d1.push_back(d2.front());
            d2.pop_front();
        }
        n--;
    }
    return 0;

}