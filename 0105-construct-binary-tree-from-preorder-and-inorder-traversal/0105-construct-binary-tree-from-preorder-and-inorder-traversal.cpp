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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hash;
        for(int i = 0; i < inorder.size(); i++){
            hash[inorder[i]] = i ;
        }

        auto f = [&](int preStart,int preEnd,int inStart,int inEnd,auto&& f)->TreeNode*{
            if(preStart > preEnd || inStart > inEnd) return nullptr;

            TreeNode* root = new TreeNode(preorder[preStart]);

            int noLeft = hash[preorder[preStart]] - inStart;

            root->left = f(preStart+1,preStart+noLeft,inStart,hash[preorder[preStart]]-1,f);
            root->right = f(preStart+noLeft+1,preEnd,hash[preorder[preStart]]+1 , inEnd,f); 

            return root;
        };

        return f(0,preorder.size()-1,0,inorder.size()-1,f);
    }
};