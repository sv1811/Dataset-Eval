class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot=n;
    for (int i = 1; i<n-1; i++){
        if (nums[i]>nums[i+1]) {
            pivot=i; break;
        }
    } 
    int search=n-pivot;  
    int s=0;
    int e= search;
    while (e>s){
        int temp = (s+e)/2;
        if (nums[temp]==target) {
            return temp;
            break;
        }
        else if (nums[temp]>target) s=temp-1;
        else e = temp+1; 
    }

    int s1=search+1;
    int e1=n;
        while (e1>s1){
        int temp = (s1+e1)/2;
        if (nums[temp]==target) {
            return temp;
            break;
        }
        else if (nums[temp]>target) s1=temp-1;
        else e1 = temp+1; 
    }
    return -1;
    }
};