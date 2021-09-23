#include <iostream>
using namespace std;

void primes_1(int n){
    for(int i=2;i<=n;i++){
        bool k=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                k=false;
                break;
            }
        }
        if(k) cout << i << " ";
    }
}

long p[10000002];
//p[i]=0 => prime
//p[i]=1 => not prime

void primes_2(int n){
    for(int i=2;i*i<=n;i++){
        if(p[i]==0){
            int k=i;
            while(k+i<=n){
                k+=i;
                p[k]=1;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(p[i]==0) cout << i << " ";
    }

}

int main(){
    int n;
    cin >> n;
    primes_2(n);
    return 0;
}