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
    int mx = INT_MIN;
    int f(TreeNode* root){
        if(root == nullptr) return 0;
        int lmax = max(0,f(root->left));
        int rmax = max(0,f(root->right));

        mx = max(mx,lmax+rmax+root->val);
        return root->val + max(lmax,rmax);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return mx;
    }
};