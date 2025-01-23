#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        //  sort(nums.begin(),nums.end());
        int n=nums.size();
         vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        // pair<int,int> p;
        // p=make_pair(a[i],i);
        v.push_back(make_pair(nums[i],i));
    }
    sort(v.begin(),v.end());
        // long long sum=0;
    int left =0; int right =n-1;
    //  long long sum=0;
    while(left<right){
        // long long sum=nums[left]+nums[right];
        // long long sum=0;
        long long sum=v[left].first+v[right].first;
        if(sum<target){
            left++;
        }
      else if(sum==target){
           ans.push_back(v[left].second);
           ans.push_back(v[right].second);
           return ans;
        }
        else{
             
             right--;
        }
    }
     return {-1,-1};
    }
};