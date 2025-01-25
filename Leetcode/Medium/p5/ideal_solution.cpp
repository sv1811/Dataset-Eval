#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string str = "#";
    for (auto c : s) {
      str.push_back(c);
      str.push_back('#');
    }

    int n = str.length();

    vector<int> radii(n, 0);
    int center = 0;
    int processed = 0;

    int start = 0;
    int max_length = 0;

    for (int i = 0; i < n; ++i) {
      int mirror = center - (i - center);
      if (i < processed) {
        radii[i] = min(processed - i, radii[mirror]);
      }

      while (i + 1 + radii[i] < n && i - 1 - radii[i] >= 0 &&
             str[i + 1 + radii[i]] == str[i - 1 - radii[i]]) {
        radii[i]++;
      }

      if (i + radii[i] > processed) {
        center = i;
        processed = i + radii[i];
      }

      if (radii[i] > max_length) {
        start = (i - radii[i]) / 2;
        max_length = radii[i];
      }
    }
    return s.substr(start, max_length);
  }
};