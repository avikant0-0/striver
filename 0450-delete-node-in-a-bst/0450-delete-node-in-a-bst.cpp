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
    TreeNode* deleteNode(TreeNode* root, int val) {
        TreeNode *dummy = new TreeNode(1e5+1);
        dummy->left = root;
        TreeNode *node = root,*prev = dummy;
        while(node){
          
            if(node->val<val) prev = node, node = node->right;
            else if(node->val>val) prev = node, node = node->left;
            else break;
          

        }
        if(!node) return root;

        // if(!prev){
        //     if(!node->left && !node->right){
        //         return nullptr;
        //     }
        //     if(!node->left || !node->right){
        //         if(node->left) return root->left;
        //         else return root->right;
        //     }
        //     TreeNode* to_attach = node->left;
        //     TreeNode* left_most = node->right;

        //     while(left_most->left != nullptr) left_most = left_most->left;

        //     left_most -> left = to_attach;
        //     return root->right;
        // }

        
        if(!node->left && !node->right){
            if(prev->val > node->val) {
                prev->left = nullptr;
                return dummy->left;
            }else{
                prev->right = nullptr;
                return dummy->left;
            }
        }

        if(!node->left || !node->right){
            if(prev->val > node->val) {
                prev->left = (node->left? node->left: node->right);
                return dummy->left;
            }else{
                prev->right = (node->left? node->left: node->right);
                return dummy->left;
            }
        }

        TreeNode* to_attach = node->left;
        if(prev->val > node->val) {
            prev->left = node->right;
        }else{
            prev->right = node->right;
        }

        TreeNode* left_most = node->right;
        while(left_most->left != nullptr) left_most = left_most->left;

        left_most -> left = to_attach;

        return dummy->left;
    }
};