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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        auto f = [&](TreeNode* root,int i, int j, auto&& f){
            if(!root) return;
            mp[j].push_back({i,root->val});
            f(root->left, i + 1, j - 1, f);
            f(root->right, i + 1, j + 1, f);
        };
        vector<vector<int>> res;
        if(!root) return res;

        f(root,0,0,f);

        for(auto i : mp) {
            sort(i.second.begin(),i.second.end(),[&](auto a, auto b){
                if(a.first != b.first) return a.first < b.first;
                else return a.second < b.second; 
            });
            vector<int> temp ;
            for(auto j : i.second) temp.push_back(j.second);
            res.push_back(temp);
        }
        return res;
    }
};