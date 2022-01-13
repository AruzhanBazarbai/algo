// /*
// Задача №165. Банкет
// На банкет были приглашены N Очень Важных Персон (ОВП). 
// Были поставлены 2 стола. Столы достаточно большие, 
// чтобы все посетители банкета могли сесть за любой из них. 
// Проблема заключается в том, что некоторые ОВП не ладят друг с другом 
// и не могут сидеть за одним столом. Вас попросили определить, 
// возможно ли всех ОВП рассадить за двумя столами.

// Входные данные
// В первой строке входных данных содержатся два числа: N и M 
// (1 <= N,M <= 100), где N – количество ОВП, а M – количество пар ОВП,
//  которые не могут сидеть за одним столом. В следующих M строках 
//  записано по 2 числа – пары ОВП, которые не могут сидеть за одним столом.

// Выходные данные
// Если способ рассадить ОВП существует, то  выведите YES в первой 
// строке и номера ОВП, которых необходимо посадить за первый стол, во второй строке. В противном случае в первой и единственной строке выведите NO.
// */
#include <iostream>
#include <vector>
using namespace std;
// done
int n,m,x,y,v,cnt_1=0,cnt_2=0;

int color[105];
vector<int> g[105];
bool ok=true;

void dfs(int v,int c){ //O(n) n-количество ребер, color[i]=0,1,2
    color[v]=c;
    if(c==1) cnt_1++;
    else cnt_2++;
    for(int i=0;i<g[v].size();i++){
        int y=g[v][i];
        if(color[y]==0 ){
            dfs(y,3-c);
        }else{
            if(color[y]==c){
                ok=false;
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // cin >> v;
    // dfs(v-1);

    for(int i=1;i<=n;i++){
        if(color[i]==0){
            dfs(i,1);
            
        }
    }
    if(ok){
        cout << "YES" << endl;
        if(cnt_1<cnt_2){
            for(int i=1;i<=n;i++){
                if(color[i]==1) cout << i << " ";
            }
        }else{
            for(int i=1;i<=n;i++){
                if(color[i]==2) cout << i << " ";
            }
        }
        
    }
    else cout << "NO";
    
    return 0;
}