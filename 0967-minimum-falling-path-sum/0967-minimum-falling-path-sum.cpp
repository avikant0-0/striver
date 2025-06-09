class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,auto &a)
    {   
        int n = a.size();

        if(i == n - 1) return a[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int ans = 1e9;
        for(int k = -1 ; k <= 1; k++){
            if(j + k >= n || j + k < 0) continue;
            ans = min(ans,f(i+1,j+k,a) + a[i][j]);
        }

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int ans = 1e9;
        dp.assign(a.size(),vector<int>(a.size(),INT_MAX));
        for(int i = 0; i < a.size(); i++) 
            ans = min(ans,f(0,i,a));
        return ans;
    }
};