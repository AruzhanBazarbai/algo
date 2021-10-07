///53 task
// Контейнеры
#include <iostream>
#include <stack>
#include <queue>
// done
// собственное решение
using namespace std;
int main(){
    int n,m,x;
    size_t cnt1=0,cnt2=0;
    cin >> n;
    stack<int> a[n+20];
    bool k=true;
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){
        cin >> m;
        for(int j=1;j<=m;j++){
            cin >> x;
            a[i].push(x);
            if(i!=x) k=false;
            if(x==1) cnt1++;
            if(x==2) cnt2++;
        }
    }
    if(k) return 0;
    else if(n==1 && !k) cout << 0;
    else if(n==2 && !k){
 
        while(!a[2].empty()){
            q.push(make_pair(2,1));
            a[1].push(a[2].top());
            a[2].pop();
        }
        while(a[1].top()==2 && !a[1].empty()){
            q.push(make_pair(1,2));
            a[2].push(a[1].top());
            a[1].pop();
        }
        if(a[1].size()!=cnt1){
            cout << 0;
        }else{
            while(!q.empty()){
                cout << q.front().first << " " << q.front().second << endl;
                q.pop();
            }
        }
    }else if(n>2){
        for(int i=2;i<=n;i++){
            while(!a[i].empty()){
                q.push(make_pair(i,1));
                a[1].push(a[i].top());
                a[i].pop();
                // cout << "-----1" << endl;
            }
        }
        while(!a[1].empty()){
            if(a[1].top()==1 || a[1].top()==2){
                q.push(make_pair(1,2));
                a[2].push(a[1].top());
                a[1].pop();
                // cout << q.front().first << " " << q.front().second << endl;
                // cout << q.back().second << " " << q.back().first << endl;
                // cout << "-----2" << endl;
            }else{
                q.push(make_pair(1,a[1].top()));
                a[a[1].top()].push(a[1].top());
                a[1].pop();
                // cout << "-----3" << endl;
            }
            
        }
        while(!a[2].empty()){
            if(a[2].top()==1){
                q.push(make_pair(2,1));
                a[1].push(a[2].top());
                // cout << "-----4" << endl;
            }else if(a[2].top()==2){
                q.push(make_pair(2,3));
                a[3].push(a[2].top());
                // cout << "-----5" << endl;
            }
            a[2].pop();
        }
        while(!a[3].empty() && a[3].top()==2){
            q.push(make_pair(3,2));
            a[2].push(a[3].top());
            a[3].pop();
            // cout << "-----6" << endl;
        }
        while(!q.empty()){
            cout << q.front().first << " " << q.front().second << endl;
            q.pop();
            // cout << "-----7" << endl;
        }
    }
    return 0;

}