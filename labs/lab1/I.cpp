//53 task
// Контейнеры
#include <iostream>
#include <stack>
#include <deque>
using namespace std;
// done
int main(){
    
    int n,k,x;
    size_t cnt1=0;
    cin >> n;
    bool res=true;
    stack<int> a[n+15];
    deque< pair<int, int> > q;

    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> x;
            a[i].push(x);
            if(x!=i) res=false;
            if(x==1) cnt1++;

        }

    }
    if(res){
        return 0;
    }else if(n<2){
        // cout << 0 << endl;
        return 0;
    }else if(n>=2){
        for(int i=2;i<=n;i++){
            while(!a[i].empty()){
                // cout << a[i].top() << endl << "0000";
                q.push_back(make_pair(i,1));
                a[1].push(a[i].top());
                a[i].pop();
                // cout << "---1" << endl;
            }
        }
        if(n==2){
            while(a[1].top()!=1){
                a[2].push(a[1].top());
                a[1].pop();
                q.push_back(make_pair(1,2));

            }
            if(a[1].size()!=cnt1){
                cout << 0 << endl;
                return 0;
            }
        }else if(n>2){
            
            while(!a[1].empty()){
                if(a[1].top()==1 || a[1].top()==2){
                    q.push_back(make_pair(1,2));
                    a[2].push(a[1].top());
                    a[1].pop();
                    
                }else{
                    q.push_back(make_pair(1,a[1].top()));
                    a[a[1].top()].push(a[1].top());
                    a[1].pop();
                    // cout << "---3" << endl;
                }
            }
            while(!a[2].empty()){
                if(a[2].top()==1){
                    q.push_back(make_pair(2,1));
                    a[1].push(a[2].top());
                    a[2].pop();
                    // cout << "---4" << endl;
                }else if(a[2].top()==2){
                    q.push_back(make_pair(2,3));
                    a[3].push(a[2].top());
                    a[2].pop();
                        // cout << "---5" << endl;

                }

            }
            while(!a[3].empty() && a[3].top()==2){
                q.push_back(make_pair(3,2));
                a[2].push(a[3].top());
                a[3].pop();
                // cout << "---6" << endl;
            }
        }

    }

    

    // while(!q.empty()){
    //     cout << q.front().first << " " << q.front().second << endl;
    //     q.pop_front();
    // }

    deque< pair<int, int> > :: iterator it;
    for(it=q.begin();it!=q.end();it++){
        cout << it->first << " " << it->second << endl;
    }

 
}