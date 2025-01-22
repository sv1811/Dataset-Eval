class Solution {
public:
    vector<int> nge(vector<int> h, bool rev = false){
        stack<pair<int, int>> st;
        int n = h.size();
        // cout<<n<<"\n";
        if(rev){
            for(int i = n-1; i>=0; i--){  
                st.push({h[i], i});
            }
        }else{
            for(int i = 0; i<n; i++){  
                st.push({h[i], i});
            }
        }
        vector<int> temp;
        int maxi = st.top().first;  int max_ind = st.top().second;st.pop();
        // cout<<max_ind;
        temp.push_back(-1);
        while(!st.empty()){
            int curr = st.top().first; int ind = st.top().second; st.pop();
            if(maxi>curr){
                temp.push_back(max_ind);
                continue;
            }
            maxi = curr;
            max_ind = ind;
            temp.push_back(-1);
        }
        
        return temp;

    }
    int trap(vector<int>& height) {
        vector<int> f = nge(height);
        vector<int> b = nge(height, true);
        reverse(f.begin(), f.end());
        int n = f.size();
        // for(int i = 0; i<n; i++) cout<<f[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i<n; i++) cout<<b[i]<<" ";
        // cout<<endl;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(f[i]==-1 or b[i]==-1) continue;
            // cout<<min(height[f[i]], height[b[i]])<<"\n";
            ans += min(height[f[i]], height[b[i]])-height[i];
        }
        return ans;
    }
};