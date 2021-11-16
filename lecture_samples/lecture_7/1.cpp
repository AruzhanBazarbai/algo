// нужно найти хэш от строк

#include <iostream>
using namespace std;

long long get_hash(string s){
    long long hash=0,p_pow=1;
    int p=31;
    for(int i=0;i<s.size();i++){
        hash+=(s[i]-'a'+1)*p_pow;
        p_pow*=p;
    }
    return hash;
}
int main(){
    string s;
    cin >> s;
    cout << get_hash(s);
    return 0;
}