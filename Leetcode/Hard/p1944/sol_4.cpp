#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        vector<int>ans(n, 0), v;
        for(int i =0; i < n; i++){
            while(!v.empty() && h[v.back()] <= h[i]){
                ans[v.back()]++;
                v.pop_back();
            }
            if(!v.empty())ans[v.back()]++;
            v.push_back(i);
        }
        return ans;
    }
};