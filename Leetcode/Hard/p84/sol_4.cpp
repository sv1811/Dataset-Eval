#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NSR(vector<int> &arr){
        int n=arr.size();
        stack<pair<int,int> > st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top().second;
            }else if(st.empty()){
                ans[i]=n;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    vector<int> NSL(vector<int> &arr){
        int n=arr.size();
        stack<pair<int,int> > st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top().second;
            }else if(st.empty()){
                ans[i]=-1;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> right=NSR(arr);
        vector<int> left=NSL(arr);
        vector<int> width(n);
        vector<int>area(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            width[i]=right[i]-left[i]-1;
            area[i]=width[i]*arr[i];
            mx=max(area[i],mx);
        }
        return mx;
    }
};