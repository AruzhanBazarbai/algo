//310 task
// Проверка на простоту_0
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
//done

void prime(int n){
    bool k=true;;
    double d=sqrt(n);
    if(n==2 || n==3){
        k=true;
    }else if(n>3){
        for(int i=2;i<=d;i++){
            // double a=n%i;
            if(n%i==0){
                k=false;
                break;
            }
        }
    }

    if(k) cout << "prime";
    else cout << "composite";
}

int main(){
    int n;
    cin >> n;
    prime(n);
    return 0;
}