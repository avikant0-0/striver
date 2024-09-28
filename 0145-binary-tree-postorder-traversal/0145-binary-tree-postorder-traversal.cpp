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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<int> st2;
        vector<int> res;
        if(root == nullptr) return res;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root->val);
            if(root->left != nullptr) st1.push(root->left);
            if(root->right!= nullptr) st1.push(root->right);
        }
        while(!st2.empty()){
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }
};