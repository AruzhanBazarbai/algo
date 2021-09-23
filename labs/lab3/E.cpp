// Задача №1440. Серебряная медаль
#include <iostream>
using namespace std;
// done
int main(){
    int n,x,max=-1e9,res=-1e9;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(max<a[i]){
            // res=max;
            max=a[i];
        }
        // if(x<max && x>res){
        //     res=x;
        // }
    }
    for(int i=0;i<n;i++){
        if(a[i]<max && a[i]>res){
            res=a[i];
        }
    }
    cout << res;

    return 0;
}