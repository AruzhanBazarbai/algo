// /*
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
#include <vector>
using namespace std;
// done
int main(){
    string s,t;
    cin >> s >> t;
    long long p[50000];
    p[0]=1;
    for(int i=1;i<50000;i++) p[i]=p[i-1]*31;
    long long hashes[s.size()];
    long long h=0;
    for(int i=0;i<t.size();i++){
        h+=(t[i]-'a'+1)*p[i];
    }

    for(int i=0;i<s.size();i++){
        hashes[i]=(s[i]-'a'+1)*p[i];
        if(i) hashes[i]+=hashes[i-1];
        if(i>=t.size()-1){
            long long cur_h=hashes[i];
            if(i-t.size()+1>0) cur_h-=hashes[i-t.size()];
            if(cur_h==h*p[i-t.size()+1]) cout << i+1-t.size() << " ";
        }
    }
}