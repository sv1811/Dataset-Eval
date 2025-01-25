#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const static int N = 1e5;
    pair<int,int> st[4*N+5];
    void build(int idx, int l, int r, vector<int> &h){
        if(l>r) return;
        if(l==r){
            st[idx]={h[l], l};
            return;
        }
        int mid=(l+r)/2;
        int lx = 2*idx, rx = 2*idx+1;
        build(lx, l, mid, h);
        build(rx, mid+1, r, h);
        if(st[lx].first < st[rx].first){
            st[idx] = st[lx];
        } else {
            st[idx] = st[rx];
        }
    }
    pair<int,int> get(int idx, int l, int r, int p, int q){
        if(l>q or r<p) return {1e9, -1};
        if(l>=p and r<=q){
            return st[idx];
        }
        int mid=(l+r)/2;
        int lx = 2*idx, rx = 2*idx+1;
        auto lm = get(lx, l, mid, p, q), rm = get(rx, mid+1, r, p, q);
        if(lm.first < rm.first) return lm;
        else return rm;
    }
    int mx=0;
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        build(1, 0, n-1, heights);
        check(0, n-1, n);
        return mx;
    }
    void check(int l, int r, int n){
        if(l>r){
            return;
        }
        auto mn = get(1, 0, n-1, l, r);
        mx=max(mx, (r-l+1)*mn.first);
        check(l, mn.second-1, n);
        check(mn.second+1, r, n);
    }
};