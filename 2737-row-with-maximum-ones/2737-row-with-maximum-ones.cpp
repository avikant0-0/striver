class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<int> res;
        for(int i = 0; i < m; i++){
            int ones = 0;
            for(int j = 0; j < n; j++) ones += (a[i][j] == 1);
            if(res.empty() || res[1] < ones) res = {i,ones}; 
        }
        return res;
    }
};