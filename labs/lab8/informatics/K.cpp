/*
Задача №2001. Числа
Витя хочет придумать новую игру с числами. В этой игре от игроков требуется преобразовывать четырехзначные числа не содержащие нулей 
при помощи следующего разрешенного набора действий:
1. Можно увеличить первую цифру числа на 1, если она не равна 9.
2. Можно уменьшить последнюю цифру на 1, если она не равна 1.
3. Можно циклически сдвинуть все цифры на одну вправо.
4. Можно циклически сдвинуть все цифры на одну влево.
Например, применяя эти правила к числу 1234 можно получить числа 2234, 1233, 4123 и 2341 соответственно. 
Точные правила игры Витя пока не придумал, но пока его интересует вопрос, как получить из одного числа другое за 
минимальное количество операций.
Входные данные
Во входном файле содержится два различных четырехзначных числа, каждое из которых не содержит нулей.
Выходные данные
Программа должна вывести последовательность четырехзначных чисел, не содержащих нулей. 
Последовательность должна начинаться первым из данных чисел и заканчиваться вторым из данных чисел, 
каждое последующее число в последовательности должно быть получено из предыдущего числа применением одного из правил. 
Количество чисел в последовательности должно быть минимально возможным.

Примеры
входные данные
1234
4321
выходные данные
1234
2234
3234
4323
4322
4321
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
// done
int f1(int n){
    if(n/1000!=9) return n+1000;
    return n;
}

int f2(int n){
    if(n%10!=1) return n-1;
    return n;
}

int f3(int n){
    int x=n/10;
    int y=n%10;
    return y*1000+x;
}

int f4(int n){
    int x=n%1000;
    int y=n/1000;
    return x*10+y;
}

int main(){
    int start,end;
    cin >> start >> end;
    map<int,int> path,distance;
    vector<int> ans;
    queue<int> q;
    q.push(start);
    distance[start]=0;
    path[start]=-1;

    while(!q.empty()){
        int v=q.front();
        int a=f1(v);
        int b=f2(v);
        int c=f3(v);
        int d=f4(v);
        // cout << v << endl << a << " " << b << " " << c << " " << d << endl;
        if(path.count(a)==0){
            path[a]=v;
            distance[a]=distance[v]+1;
            q.push(a);
        }
        if(path.count(b)==0){
            path[b]=v;
            distance[b]=distance[v]+1;
            q.push(b);
        }
        if(path.count(c)==0){
            path[c]=v;
            distance[c]=distance[v]+1;
            q.push(c);
        }
        if(path.count(d)==0){
            path[d]=v;
            distance[d]=distance[v]+1;
            q.push(d);
        }
        if(a==end || b==end || c==end || d==end){
            int temp=end;
            while(temp!=-1){
                ans.push_back(temp);
                temp=path[temp];
            }
            reverse(ans.begin(),ans.end());
            for(int x:ans) cout << x << endl;
            return 0;
        }
        q.pop();
    }
}