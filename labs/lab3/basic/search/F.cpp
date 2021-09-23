//Задача №1447. Контроперация
#include <iostream>
#include <vector>
// done
using namespace std;
int main(){
    int n,max=-1e9,min=1e9;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i]>max) max=v[i];
        if(v[i]<min) min=v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i]==max) cout << min << " ";
        else cout << v[i] << " ";
    }
    return 0;
}