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
    int countNodes(TreeNode* root) {
        
        auto getlh = [&](TreeNode* root){
            int ht = 0 ;
            while(root)
            {
                ++ht; 
                root = root->left; 
            }
            return ht ; 
        };

        auto getrh = [&](TreeNode* root){
            int ht = 0 ;
            while(root)
            {
                ++ht; 
                root = root->right; 
            }
            return ht; 
        };


        auto f = [&](TreeNode* root,auto&& f)->int{
            if(!root) return 0;

            int lh = getlh(root);
            int rh = getrh(root);

            // cout << lh <<" " << rh << endl;

            if(lh == rh) return pow(2,lh)-1;

            return f(root->left,f) + f(root->right,f) + 1; 
        };

      
        return f(root,f);
    }
};