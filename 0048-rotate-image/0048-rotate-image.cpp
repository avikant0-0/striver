class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                if(j>=i)swap(a[i][j],a[j][i]);
            }
        }
        for(int i = 0; i < a.size(); i++){
            reverse(a[i].begin(),a[i].end());
        }
    }
};