class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = 0;
        int n = nums.size() - 1;
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int mid = (l+h)/2;
            if (mid<n&&nums[mid] > nums[mid + 1]) {idx = mid; break;}
            if (nums[mid] < nums[n]) h = mid - 1;
            else l = mid + 1;
        }
        if(idx==0){l=0; h=n;}
        else {
            if(target<nums[0]){l=idx+1; h=n;}
            else{l=0; h=idx;}
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            else if(target<nums[mid]) h=mid-1;
            else l=mid+1;
        }
        return -1;
    
    }
};