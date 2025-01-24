// **Variant 5: Using Overwrite Technique with Skip Counter**
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int writeIndex = 1;
    int skipCount = 0;
    int currNum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == currNum) {
            skipCount++;
            if (skipCount < 2) {
                nums[writeIndex++] = nums[i];
            }
        } else {
            skipCount = 0;
            currNum = nums[i];
            nums[writeIndex++] = nums[i];
        }
    }
    
    return writeIndex;
}
