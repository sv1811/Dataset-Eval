// Variant 5: Two Pointers with Binary Search Optimization
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};
        } else if (sum < target) {
            // Use binary search to find the next left
            int low = left + 1, high = right;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (numbers[mid] + numbers[right] == target) {
                    return {mid + 1, right + 1};
                } else if (numbers[mid] + numbers[right] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            left = low;
        } else {
            // Use binary search to find the next right
            int low = left, high = right - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (numbers[left] + numbers[mid] == target) {
                    return {left + 1, mid + 1};
                } else if (numbers[left] + numbers[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            right = high;
        }
    }
    
    return {};
}
