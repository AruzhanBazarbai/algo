#include <iostream>
using namespace std;
// 
int arr[801][801];
int n,m;
void bs(int x,int i){
    if(i%2==0){
        if(x<=arr[i][0] && x>=arr[i][m-1]){
            bool ok=false;
            int l=0,r=m-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[i][mid]==x){
                    cout << i << " " << mid << endl;
                    ok=true;
                    break;
                }else if(arr[i][mid]>x){
                    l=mid+1;
                }else r=mid-1;
            }
            if(!ok) cout << -1 << endl;
        }else{
            if(i+1!=n) bs(x,i+1);
            
        }
    }else{
        if(x>=arr[i][0] && x<=arr[i][m-1]){
            int l=0,r=m-1;
            bool ok=false;
            while(l<=r){
                int mid=(l+r)/2;
                if(arr[i][mid]==x){
                    cout << i << " " << mid << endl;
                    ok=true;
                    break;
                }else if(arr[i][mid]>x){
                    r=mid-1;
                }else l=mid+1;
            }
            if(!ok) cout << -1 << endl;
        }else{
            if(i+1!=n) bs(x,i+1);
            
        }
    }
    
}

int main(){
    int k;
    cin >> k;
    int a[k];
    for(int i=0;i<k;i++) cin >> a[i];

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        if(n%2==0){
            if(a[i]>arr[0][0] || a[i]<arr[n-1][0]){
                cout << -1 << endl;
            }else bs(a[i],0);
        }else{
            if(a[i]>arr[0][0] || a[i]<arr[n-1][m-1]){
                cout << -1 << endl;
            }else bs(a[i],0);
        }
        
       
    }


    return 0;
}