// Variant 4: Two Pointers with Early Exit
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            left++;
            // Skip duplicates
            while (left < right && numbers[left] == numbers[left - 1]) left++;
        } else {
            right--;
            // Skip duplicates
            while (left < right && numbers[right] == numbers[right + 1]) right--;
        }
    }
    
    return {};
}
