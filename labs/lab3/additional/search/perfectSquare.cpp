//367. Valid Perfect Square
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=0,r=num;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num)  r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};