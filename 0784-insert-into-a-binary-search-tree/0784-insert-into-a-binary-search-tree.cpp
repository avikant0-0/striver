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
    void dfs(TreeNode* root,auto& arr){
        if(!root) return;
        arr.push_back(root);
        dfs(root->left,arr);
        dfs(root->right,arr);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        vector<TreeNode*> nodes;
        dfs(root,nodes);
        TreeNode* valnode = new TreeNode(val);
        nodes.push_back(valnode);
        sort(nodes.begin(),nodes.end(),[&](auto& a,auto& b){
            return a->val < b->val;
        });
        if(nodes.size() == 0) return nullptr;
        if(nodes.size() == 1){
            return nodes[0];
        }
        root = nodes[0];

        for(int i = 1; i < nodes.size(); i++){
            root->right = nodes[i];
            root->left = nullptr;
            root = root->right;
        }
        nodes[nodes.size()-1]->right = nullptr;
        nodes[nodes.size()-1]->left = nullptr;

        return nodes[0];
    }
};