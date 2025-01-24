// **Variant 2: Two Pointers with Previous Element Tracking**
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int k = 2;  // Start from index 2 as first two elements are always valid
    
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[k-2]) {
            nums[k] = nums[i];
            k++;
        }
    }
    
    return k;
}
