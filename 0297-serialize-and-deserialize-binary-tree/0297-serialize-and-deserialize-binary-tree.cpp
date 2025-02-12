/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root) return "";

        queue<TreeNode*> q; 
        string en; 
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front == nullptr) {
                    en += "#,";
                    continue;
                }

                en += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }

        return en; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                getline(s,str,',');
                if(str == "#"){
                    front->left = nullptr;
                }else {
                    front->left = new TreeNode(stoi(str));
                    q.push(front->left);
                }

                getline(s,str,',');
                if(str == "#"){
                    front->right = nullptr;
                }else {
                    front->right = new TreeNode(stoi(str));
                    q.push(front->right);
                }
            }
        }

        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));