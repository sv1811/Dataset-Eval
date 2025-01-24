#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
     int n = heights.size();
      if(n==1) return {0};
      
       vector <int> v(heights.size() , 0);
   stack <int>st;

    st.push(heights[n-1]);  
    for(int i = n-2; i>=0; i--)
    {
    int count = 0;
    while(st.size() > 0 and st.top() < heights[i])
    {
    st.pop();
    count ++;
    }

   if(st.size() !=0)
   count +=1;

   v[i] = count;


    st.push(heights[i]);

    }


      return v; 
    }
};