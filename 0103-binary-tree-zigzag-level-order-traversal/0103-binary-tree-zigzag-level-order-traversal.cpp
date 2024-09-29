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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(root == nullptr) return res; 
        bool islefttoright = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0;i < size;i++){
                TreeNode* front = q.front();
                q.pop();
                int index = (islefttoright ? i : size - i - 1);
                level[index] = front->val;
                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
            }
            islefttoright = !islefttoright;
            res.push_back(level);
        }
        return res;
    }
};