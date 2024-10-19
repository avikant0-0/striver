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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;

        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            result.push_back(top->val);
            st.pop();
            if(top->right != nullptr) st.push(top->right);
            if(top->left  != nullptr) st.push(top->left);
        } 

        return result ;
    }
};