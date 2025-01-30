#include <vector>
#include <unordered_map>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    unordered_map<int, int> freq;
    int writeIndex = 0;
    for (int num : nums) {
        if (freq[num] < 2) {
            nums[writeIndex++] = num;
            freq[num]++;
        }
    }
    return writeIndex;
}
