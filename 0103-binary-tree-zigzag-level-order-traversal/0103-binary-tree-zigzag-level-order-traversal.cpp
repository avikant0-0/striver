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
        q.push(root);
        vector<vector<int>> result; 
        if(!root) return result ;

        int even = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level ;
            for(int i =0; i < size; i++){
                TreeNode* front = q.front();

                q.pop();


                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);


                level.push_back(front->val);
            }
            if(even%2 == 1) {
                reverse(level.begin(),level.end()); 
            }
            ++even; 

            result.push_back(level);
        }

        return result; 
    }
};