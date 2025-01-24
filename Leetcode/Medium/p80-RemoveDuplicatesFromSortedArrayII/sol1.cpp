// **Variant 1: Two Pointers with Count Variable**
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    
    int count = 1;
    int writeIndex = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if (count <= 2) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }
    
    return writeIndex;
}
