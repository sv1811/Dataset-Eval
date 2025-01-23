class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        
        vector<int> dp(n,1);
        int maxlen = 1;
        for(int i = 1;i<n;++i){
            for(int j = 0;j<i;++j){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);

            }
            maxlen = max(maxlen,dp[i]);
        }
        return maxlen;
    }
};