class Solution {
public:
    int search(vector<int>& nums, int target) {
    int index=0;
    int n=nums.size();
//**********FINDING THE INDEX ABOUT WHICH THE ARRAY WAS ROTATED*****************
    int s=0;
    int e=n-1;
while (s<e) {
    int temp = (s+e)/2;
    if (nums[temp]>nums[temp+1]) {index=temp+1;
    break;}
    else if (nums[temp]>nums[s]) s=temp;
    else if (nums[temp]<nums[s]) e=temp;
    } 
//*********************************************************************************
//*********** BINARY SEARCH FOR THE TARGET******************************
if (target<nums[0]) /*It should search in index to n-1*/{
s=index;
e=n-1;
while (s<=e) {
    int temp = (s+e)/2;
    if (nums[temp]==target) return temp;
    else if (nums[temp]>target) e=temp-1;
    else s=temp+1;
} 
}

else /*It should search in 0 to index-1*/ {
s=0;
e=index-1;
while (s<=e) {
    int temp = (s+e)/2;
    if (nums[temp]==target) return temp;
    else if (nums[temp]>target) e=temp-1;
    else s=temp+1;
}
}
return -1;
    }
};