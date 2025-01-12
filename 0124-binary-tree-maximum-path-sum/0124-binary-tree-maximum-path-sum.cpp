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
    int findans(TreeNode* root,int &ans){
        if(!root) return 0; 

        int lh = max(0,findans(root->left,ans));
        int rh = max(0,findans(root->right,ans));

        ans = max(ans, lh + rh + root->val);

        return max(lh,rh) + root->val; 
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e9 ;
        findans(root,ans);
        return ans; 
    }
};