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
    stack<TreeNode*> st1,st2;
    void pushLeft(TreeNode* root,stack<TreeNode*>& st){
        while(root){
            st.push(root);
            root = root->left; 
        }
    }
    void pushRight(TreeNode* root,stack<TreeNode*>& st){
        while(root){
            st.push(root);
            root = root->right; 
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        pushLeft(root,st1);
        pushRight(root,st2);

        while(st1.size() && st2.size()){
            int sum = st1.top()->val  + st2.top()->val;
            if(st1.top() == st2.top()){
                TreeNode* top = st2.top();
                st2.pop();
                pushRight(top->left,st2);
                continue;
            }
            if(sum > k){
                TreeNode* top = st2.top();
                st2.pop();
                pushRight(top->left,st2);
            }else if(sum < k){
                TreeNode* top = st1.top();
                st1.pop();
                pushLeft(top->right,st1);
            }else return true; 
        }
        return false;
    }
};