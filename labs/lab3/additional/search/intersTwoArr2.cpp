// 350. Intersection of Two Arrays II
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    v.push_back(nums1[i]);
                    nums2[j]=-1;
                    nums1[i]=-2;
                    break;
                }
            }
        }
        return v;
    }
};