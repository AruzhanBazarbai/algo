#include <iostream>
#include <queue>
using namespace std;
//lcm

int gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    long a,b;
    cin >> a >> b;
    int x=gcd(a,b);
    long lcm=(a*b)/x;
    cout << lcm << endl;
    return 0;
    
}