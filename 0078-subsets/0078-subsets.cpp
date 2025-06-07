class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        for(int i = 0; i < (1<<(a.size())); i++)
        {
            vector<int> temp;
            for(int j = 0; j <= 31; j++){
                int totake = ((i>>j)&1);
                if(totake) temp.push_back(a[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};