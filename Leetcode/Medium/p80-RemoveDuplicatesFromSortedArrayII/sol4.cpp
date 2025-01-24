// **Variant 4: Using Window Sliding Technique**
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int left = 0;
    int count = 1;
    
    for (int right = 1; right < nums.size(); right++) {
        if (nums[right] != nums[right-1]) {
            nums[++left] = nums[right];
            count = 1;
        } else if (count < 2) {
            nums[++left] = nums[right];
            count++;
        }
    }
    
    return left + 1;
}
