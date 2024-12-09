/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(k == 0){
            return {target->val}; 
        }
        map<TreeNode*,TreeNode*> par;
        queue<TreeNode*> q;
        q.push(root);
        par[root] = NULL;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < q.size(); i++)
            {
                TreeNode* front = q.front();
                q.pop();

                if(front->left) par[front->left] = front, q.push(front->left);
                if(front->right) par[front->right] = front, q.push(front->right); 
            }
        }
    
        vector<int> ans;

        q.push(target);
        int dist = 0 ;

        vector<int> visited(501,0);

        while(!q.empty())
        {   

            int size = q.size() ;
            ++dist;

            for(int i= 0 ; i < size ;i++)
            {
                TreeNode* front = q.front() ;
                q.pop() ; 
                visited[front->val] = 1; 

                if(front->left && !visited[front->left->val]) {
                    if(dist == k) ans.push_back(front->left->val);
                    else {
                        q.push(front->left);
                    }
                }

                if(front->right && !visited[front->right->val]) {
                    if(dist == k) ans.push_back(front->right->val);
                    else {
                        q.push(front->right);
                    }
                }

                if(par[front] != NULL && !visited[par[front]->val]) {
                    if(dist == k) ans.push_back(par[front]->val);
                    else {
                        q.push(par[front]);
                    }
                }
            }
        }

    
        return ans; 

    }

};