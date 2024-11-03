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
        map<int,int> mp ;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i ;
        }
        return f(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
    }

    TreeNode* f(auto& preorder,auto& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>& mp){

        if(preStart > preEnd || inStart > inEnd) return nullptr; 

        TreeNode* root = new TreeNode(preorder[preStart]);
        int numleft = mp[preorder[preStart]] - inStart;

        root->left = f(preorder,inorder,preStart+1,preStart+numleft,inStart,mp[preorder[preStart]]-1,mp);
        root->right = f(preorder,inorder,preStart + numleft + 1 , preEnd,mp[preorder[preStart]] + 1 , inEnd, mp);

        return root ; 
    }
};