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
    TreeNode* dfs(int& i,int ub,vector<int>& preorder){
        if(i == preorder.size() || preorder[i] > ub) return nullptr;
        TreeNode* root = new TreeNode(preorder[i++]);

            root->left = dfs(i,preorder[i-1],preorder);
            root->right =dfs(i,ub,preorder);

        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(i,INT_MAX,preorder);
    }
};