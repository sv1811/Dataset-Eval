// Level-order Construction
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        int n = nums.size();
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        int mid = n / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        q.push({root, {0, mid - 1}});
        q.push({root, {mid + 1, n - 1}});
        
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            TreeNode* parent = curr.first;
            int left = curr.second.first;
            int right = curr.second.second;
            
            if (left <= right) {
                mid = left + (right - left) / 2;
                TreeNode* newNode = new TreeNode(nums[mid]);
                
                if (nums[mid] < parent->val)
                    parent->left = newNode;
                else
                    parent->right = newNode;
                
                q.push({newNode, {left, mid - 1}});
                q.push({newNode, {mid + 1, right}});
            }
        }
        
        return root;
    }
};
