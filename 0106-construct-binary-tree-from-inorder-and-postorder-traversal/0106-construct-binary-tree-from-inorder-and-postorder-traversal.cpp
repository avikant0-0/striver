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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> hash;
        for(int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
        
        auto f = [&](int postStart,int postEnd,int inStart,int inEnd,auto&& f)->TreeNode* {
            if(postStart > postEnd || inStart > inEnd) return nullptr;

            TreeNode* root = new TreeNode(postorder[postEnd]);
            int inRoot = hash[postorder[postEnd]];
            int noLeft = inRoot - inStart;

            root->left =  f(postStart,postStart+noLeft-1,inStart,inRoot-1,f);
            root->right = f(postStart+noLeft,postEnd-1,inRoot+1,inEnd,f);

            return root; 
        };

        return f(0,postorder.size()-1,0,inorder.size()-1,f);
    }
};