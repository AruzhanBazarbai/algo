#include <iostream>
using namespace std;
// done
long long a[510][510];
pair<int,int> b[510];
int n,m;
void merge(int l,int r,int mid){
    int n1=mid-l+1,n2=r-mid;
    pair<int,int> R[n2],L[n1];
    for(int i=0;i<n1;i++) L[i]=b[l+i];

    for(int i=0;i<n2;i++) R[i]=b[mid+i+1];

    int uk1=0,uk2=0,k=l;
    
    while(uk1<n1 && uk2<n2){
        if(L[uk1].second>R[uk2].second){
            b[k]=L[uk1];
            uk1++;
        }else if(L[uk1].second<R[uk2].second){
            b[k]=R[uk2];
            uk2++;
        }else if(L[uk1].second==R[uk2].second){
            int ind=0;
            while(a[L[uk1].first][ind]==a[R[uk2].first][ind]){
                ind++;
            }   
            if(a[L[uk1].first][ind]<a[R[uk2].first][ind]){
                b[k]=L[uk1];
                // k++;
                // b[k]=R[uk2];
                uk1++;
                // uk2++;
            }else{
                b[k]=R[uk2];
                // k++;
                // b[k]=L[uk2];
                // uk1++;
                uk2++;
            }
        }
        k++;
    }

    while(uk1<n1){
        b[k]=L[uk1];
        uk1++;
        k++;
    }

    while(uk2<n2){
        b[k]=R[uk2];
        uk2++;
        k++;
    }




}

void merge_sort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        merge(l,r,mid);
    }
}
int main(){
    cin >> n >> m;
    // int a[n][m+1];
    
    for(int i=0;i<n;i++){
        long long res=0;
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            res+=a[i][j];
            if(j==m-1) b[i]=make_pair(i,res);
        }
    }
    merge_sort(0,n-1);
    // for(int i=0;i<n;i++){
    //     cout << b[i].first << " " << b[i].second;
    //     cout << endl;
    // }
    // cout << "----" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[b[i].first][j] << " ";
        }
        cout << endl;
        
    }
    

}