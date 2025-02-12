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
    vector<int> dfs(TreeNode* root,int& ans){
        if(!root) return {0,INT_MIN,INT_MAX};
        vector<int> left = dfs(root->left,ans);
        vector<int> right = dfs(root->right,ans);
        if(root->val > left[1] && root->val < right[2]){
            ans = max(ans,root->val+left[0]+right[0]);
            return {root->val+left[0]+right[0],max({root->val,left[1],right[1]}),
            min({root->val,left[2],right[2]})};
        }else{
            return {max(left[0],right[0]),INT_MAX,INT_MIN}; 
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root,ans); 
        return ans; 
    }
};