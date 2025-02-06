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
    TreeNode* dfs(int preStart,int preEnd,int inStart,int inEnd,auto& preorder,auto& inorder,auto& mp){
        if( (preStart>preEnd) || (inStart>inEnd)) return nullptr;

        int curr_root = preorder[preStart];
        TreeNode* root = new TreeNode(curr_root);
        int in_ind = mp[curr_root];

        int num_left = in_ind - inStart; 

        root->left = dfs(preStart+1,preStart+num_left,inStart,in_ind-1,preorder,inorder,mp);
        root->right = dfs(preStart+num_left+1,preEnd,in_ind+1,inEnd,preorder,inorder,mp);

        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());

        map<int,int> mp;
        int n = preorder.size();

        for(int i = 0; i < n;i++) mp[inorder[i]] = i;

        TreeNode* root;
        return dfs(0,n-1,0,n-1,preorder,inorder,mp); 
    }
};