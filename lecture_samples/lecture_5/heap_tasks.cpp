// 1- given the an array of integers nums, you will choose two different indices i and j of that array,
// return the max value of (nums[i]-1)*(nums[j]-1).
//  [3,4,5,2]-возьмем два максимума из массива и умножим
// i=1,j=2
// (4-1)*(5-1)
// priority queue is a container adaptor that provides constant time lookup of the largest(by default) element,
// at the expense of logarithmic insertion and extraction
// 2 - you are  an array of integers stones where stones[i] id the weight of the ith 
// stone.
// We are playing a game with the stones. On each turn, we choose the heaviest two stones
// and smash them together. Suppose the heaviest two stones have weights x and y with x<=y. The result of this smash is:
// if x==y, both stones are destroyed and
// if x!=y, the stone of weight x is destroyed, and the stone of the weight y has new weight y-x
// At the end of the game, there is at most one stone left
// 
// Return the smallest possible weight of the left stone. If there are no stones left, return 0
// Input: stones=[2,7,4,1,8,1]
// output:1
// 3- you are given an integer array score of size n, where score[i] is the score of the ith athlete
// in a competition. all the scores are guaranteed to be unique
// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete
// has the 2nd highest score and so on. The placement of each athlete determines their rank:
// the 1st place athlete's rank is the 'Gold Medal'.
// the 2nd 'Silver Medal'
// the 3rd 'Bronze Medal'
// for the 4st place to the nth place athlete, their rank is their placement number
// return an array answer of size n where answer[i] is the ranke of the ith athlete.
// Input: score=[5,4,3,2,1]
// output: ['Gold Medal',"Silver Medal","bronze Medal","4","5"]

#include <bits/stdc++.h> 

using namespace std;

 int maxProduct(vector<int>& nums) {
       priority_queue<int>q;
        for(auto x:nums)
        {
            q.push(x);
        }
        int p1=q.top();
        q.pop();
        int p2=q.top();
        q.pop();
        
        p1=p1-1;
        p2=p2-1;
        return p1*p2; 
    }

     vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> ans(score.size());
        int count = 1;
        for(int i = 0;i <score.size(); i++)
            pq.push(make_pair(score[i], i));
        
        while(pq.empty() ==false)
        {
            if(count == 1)
            {
                ans[pq.top().second] = "Gold Medal";
            }
            
            else if(count == 2)
            {
                ans[pq.top().second] = "Silver Medal";
            }
            else if(count == 3)
            {
                ans[pq.top().second] = "Bronze Medal";
            }
            
            else 
            {
                ans[pq.top().second] = to_string(count);
            }
            
            count++;
            pq.pop();
        }
        
        return ans;
    }

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size() !=1){
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            pq.push(st1 - st2);
        }
        return pq.top();
    }
int main(){
	vector<int> v = {2,7,4,1,8,1};
	cout << maxProduct(v);

    cout << endl << lastStoneWeight(v);
}