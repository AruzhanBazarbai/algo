// 69. Sqrt(x)
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long res,i=0;
        
        while(i*i<=x){
            res=i;
            i++;
        }
        
        return  res;
    }
};