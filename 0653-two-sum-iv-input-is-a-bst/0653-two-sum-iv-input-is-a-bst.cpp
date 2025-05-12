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
    class B_IT{
        private:
            stack<TreeNode*> left;
            stack<TreeNode*> right;
        public:
            B_IT(TreeNode* root){
                TreeNode* r = root;
                while(root) {
                    left.push(root);
                    root = root->left;
                }
                while(r){
                    right.push(r);
                    r = r->right;
                }
            }
            int next(){
                if(left.empty()){
                    return 1e5;
                }
                TreeNode* node = left.top();
                left.pop();
                int toreturn = node->val;
                if(node->right){
                    node = node->right;
                    while(node){
                        left.push(node);
                        node = node->left;
                    }
                }
                return toreturn;
            }
            int before(){
                if(right.empty()){
                    return 1e5;
                }
                TreeNode* node = right.top();
                right.pop();
                int toreturn = node->val;
                if(node->left){
                    node = node->left;
                    while(node){
                        right.push(node);
                        node = node->right;
                    }
                }
                return toreturn;
            }
    };
    bool findTarget(TreeNode* root, int k) {
        
        B_IT T(root);
        int l = T.next(),r = T.before();

        while(true){
            if(l==r){
                l = T.next();
            }
            if(l == 1e5 || r == 1e5){
                break;
            }
            if(l+r == k) return true;
            else if(l+r<k) l = T.next();
            else r = T.before();
        }
        return 0;
    }
};