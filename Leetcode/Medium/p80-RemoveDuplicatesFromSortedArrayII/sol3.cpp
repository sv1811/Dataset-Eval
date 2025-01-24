// **Variant 3: General Solution for at most K occurrences**
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    const int k = 2;  // Maximum allowed occurrences
    if (nums.size() <= k) return nums.size();
    
    int writeIndex = k;
    
    for (int readIndex = k; readIndex < nums.size(); readIndex++) {
        if (nums[readIndex] != nums[writeIndex-k]) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }
    
    return writeIndex;
}
