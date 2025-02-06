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
    void dfs(TreeNode*& root,int i,int j,vector<int>& nums){
        int n = nums.size();

        if(i > j) return;

        int mid = (i + j) / 2 ; 
        root = new TreeNode(nums[mid]);
        

        dfs(root->left,i,mid-1,nums);
        dfs(root->right,mid+1,j,nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root; 
        int n = nums.size();
        dfs(root,0,n-1,nums);
        return root;
    }
};