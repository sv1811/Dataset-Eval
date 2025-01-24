class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), i = 0, result = 0;
        stack<int> s;
        while (i < n)
        {
            if (s.empty() || height[i] < height[s.top()])
                s.push(i++);
            else
            {
                int curr = s.top();
                s.pop();
                //Right higher is i, left higher is s.top()
                int prev = (!s.empty() ? s.top() : -1);
                if (prev != -1)
                {
                    result += ((min(height[i], height[prev]) - height[curr]) * (i - prev - 1));
                }                
            }
        }
        return result;
    }
};