// /*
// Задача №1327. Период строки
// Дана непустая строка s. Нужно найти такое наибольшее число k и строку t, что s совпадает со строкой t, выписанной k раз подряд.

// Ограничение времени - 1 секунда.

// Входные данные
// Одна строка длины N, 0 < N ≤ 106, состоящая только из маленьких латинских букв.

// Выходные данные
// Одно число - наибольшее возможное k.
// */
#include <iostream> 
using namespace std;
// done
int a[1000005];
void prefix_function(string s){ //O(n)
    int n=s.size();
    
    for(int i=1;i<n;i++){
        int j=a[i-1];
        while(j>0 && s[j]!=s[i]){
            j=a[j-1];
        }
        if(s[i]==s[j]) j++;
        a[i]=j;
    }
}
int main(){
    string s;
    cin >> s;
    prefix_function(s);
    // for(int i=0;i<s.size();i++){
    //     cout << a[i] << " ";
    // }
    int n=s.size();
    int k=n-a[n-1];
    // cout << endl;
    if(n%k==0 && k>0) cout << n/k;
    else cout << 1;
    return 0;
}

