#include <iostream>
using namespace std;
//GCD

int gcd_1(int a,int b){
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0)
            return i;

    }
    return 1;

}

int gcd_2(int a,int b){
    while(a>0 && b>0){
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a==0) return b;
    return a;
    // return a+b;
}

int gcd_3(int a,int b){
    if(b==0) return a;
    return gcd_3(b,a%b);
}

int main(){
    int a,b;
    cin >> a >> b;
    int g=gcd_3(a,b);
    cout << g << endl;
    return 0;

}