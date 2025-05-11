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
    bool dfs(TreeNode* root,long long mn,long long mx){
        if(!root) return true;
        if(root->val >= mx || root->val <= mn) return false;
        bool left = dfs(root->left,mn,min(mx,(long long)root->val));
        bool right = dfs(root->right,max(mn,(long long)root->val),mx);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-1e10,1e10);
    }
};