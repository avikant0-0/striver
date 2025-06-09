class Solution {
public:
    vector<vector<int>> dp;

    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        dp.assign(n,vector<int>(n,1e9));
        
        for(int j = 0; j < n; j++) dp[0][j] = a[0][j];

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = -1; k <= 1; k++)
                {   
                    int pj = j + k;
                    if(pj >= n || pj < 0) continue;
                    int cost = a[i][j] + dp[i-1][pj];

                    dp[i][j] = min(dp[i][j],cost);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};