/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, long long lb, long long ub) {
        if (!root) return true; 
        if (root->val > ub || root->val < lb) return false;
        
        bool left = dfs(root->left, lb, static_cast<long long>(root->val) - 1);
        bool right = dfs(root->right, static_cast<long long>(root->val) + 1, ub);
        
        return left && right; 
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
