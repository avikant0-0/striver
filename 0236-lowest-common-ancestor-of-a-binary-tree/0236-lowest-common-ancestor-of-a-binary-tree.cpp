/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto f = [&](TreeNode* root, auto&& f)->TreeNode*{
            if(!root || root == p || root == q) return root;

            TreeNode* left = f(root->left,f) ;
            TreeNode* right = f(root->right,f);

            if(left && right) return root ;
            else if(left) return left ;
            else return right; 

        };
        return f(root,f);
    }
};