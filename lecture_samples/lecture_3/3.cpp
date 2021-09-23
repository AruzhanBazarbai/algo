#include <iostream>
#include <vector>
using namespace std;
//34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=(int)nums.size()-1,index1=-1,index2=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target){
                index1=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(index1==-1 || nums[index1]!=target){
            return {-1,-1};
        }
        l=0,r=(int)nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target){
                index2=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return {index1,index2};
        
    }
};