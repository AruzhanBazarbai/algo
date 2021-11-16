// /*
// Rabin Karp
// Задача №99. Поиск подстроки
// Максимальное время работы на одном тесте:	0.2 секунды
// Найти все вхождения строки T в строку S.

// Входные данные
// Первые две строки входных данных содержат строки S  и T, соответственно. Длины строк больше 0 и меньше 50000, 
// строки содержат только строчные латинские буквы.

// Выходные данные
// Выведите номера символов, начиная с которых строка T входит в строку S, в порядке возрастания.
// */
#include <iostream>
using namespace std;
int main(){
    string s,t;
    cin >> s;
    cin >> t;
    int p=31,n=s.size(),m=t.size();
    long long h[n];
    long long p_pow[n];
    long long hash=0;
    
    
    p_pow[0]=1;
    for(int i=1;i<n;i++) p_pow[i]=p_pow[i-1]*p;

    for(int i=0;i<n;i++){
        h[i]=(s[i]-'a'+1)*p_pow[i];
        if(i!=0) h[i]+=h[i-1];
    }
    for(int i=0;i<m;i++){
        hash+=(t[i]-'a'+1)*p_pow[i];
    }
    for(int i=0;i<n-m+1;i++){
        long long h1=h[i+m-1];
        if(i) h1-=h[i-1];
        
        if(i>0){
            if(hash*p_pow[i]==h1){
                cout << i << " ";
            }
        }else{
            if(hash==h1) cout << i << " ";
        }
    }
    return 0;

}