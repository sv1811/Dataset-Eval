// Iterative Solution with Stack
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        struct Item {
            TreeNode* node;
            int left, right;
            bool isLeft;
        };
        
        int left = 0, right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        stack<Item> st;
        st.push({root, left, mid - 1, true});
        st.push({root, mid + 1, right, false});
        
        while (!st.empty()) {
            Item curr = st.top(); st.pop();
            if (curr.left > curr.right) continue;
            
            mid = curr.left + (curr.right - curr.left) / 2;
            TreeNode* newNode = new TreeNode(nums[mid]);
            
            if (curr.isLeft)
                curr.node->left = newNode;
            else
                curr.node->right = newNode;
            
            st.push({newNode, curr.left, mid - 1, true});
            st.push({newNode, mid + 1, curr.right, false});
        }
        
        return root;
    }
};
