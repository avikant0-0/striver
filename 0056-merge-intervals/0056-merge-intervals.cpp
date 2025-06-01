class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        sort(I.begin(),I.end());
        vector<vector<int>> ans = {{I[0][0],I[0][1]}};
        for(int i = 1; i < I.size(); i++){
            if(I[i][0] > ans.back()[1]){
                ans.push_back(I[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],I[i][1]);
            }
        }
        return ans;
    }
};