/*
Problem D. Goldbach’s conjecture
Input file: standard input
Output file: standard output
Time limit: 1 second
Memory limit: 256 megabytes
Goldbach’s conjecture states that each even number starting from 4 can be represented as the sum of two
primes. Your task is to verify this conjecture. You are given even integer N. Find primes A and B such
that A + B = N.
Input
You are given the only integer N (4 <= N <= 100000, N is even).
Output
Print two primes A and B such that A + B = N.
*/
#include <iostream>
using namespace std;
// done
int p[10000010];
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
        if(p[i]==0){
            int k=n-i;
            if(p[k]==0){
                cout << i << " " << k << endl;
                break;
            }
        }
    }

}
int main(){
    int n;
    cin >> n;
    primes_2(n);
}