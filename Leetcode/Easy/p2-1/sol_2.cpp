#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>data;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int index=i;
            int val=nums[i];
            data.push_back({val,index});
        }
        
        //sort kr do ab
        sort(data.begin(),data.end());
        //apply 2 pointer approach
        int s=0;
        int e=n-1;
        while(s<e){
            int sum=data[s].first+data[e].first;
            if(sum==target){
                vector<int>temp;
                temp.push_back(data[s].second);
                temp.push_back(data[e].second);
                return temp;
            }
            if(sum>target){
                e--;
            }
            else{
                s++;
            }
        }
        vector<int>temp;
        return temp;
    }
};