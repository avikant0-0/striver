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
private:
    TreeNode *first = NULL,*second= NULL,*third = NULL,*prev = NULL;
public:
    void inorder(TreeNode* root){
        if(!root) return ;

        inorder(root->left);
        if(prev != nullptr && first == nullptr && root->val < prev->val){
            first = prev;
            second = root;
        }else if(prev != nullptr && first != nullptr && root->val < prev->val){
            third = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(!third){
            swap(first->val,second->val);
        }else{
            swap(first->val,third->val);
        }   
    }
};