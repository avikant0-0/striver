class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        int n = I.size();
        vector<vector<int>> ans;

        sort(I.begin(),I.end());
    
        for(int i = 0 ; i < n; i++){
            if(ans.empty() || I[i][0] > ans.back()[1]){
                ans.push_back(I[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], I[i][1]) ;
            }
        }

        return ans;
    }
};