// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <iostream>
using namespace std;

bool isBadVersion(int mid){
    
}

// 278. First Bad Version
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n,res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isBadVersion(mid)){
                res=mid;
                r=mid-1;
            }else{
                // res=mid;
                l=mid+1;
            }
        }
        return res;
        
    }
};