// Variant 1: Basic Sliding Window
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    vector<int> map(128, 0);
    for (char c : t) map[c]++;
    int counter = t.length(), begin = 0, end = 0, d = INT_MAX, head = 0;
    
    while (end < s.length()) {
        if (map[s[end++]]-- > 0) counter--;
        while (counter == 0) {
            if (end - begin < d) d = end - (head = begin);
            if (map[s[begin++]]++ == 0) counter++;
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}
