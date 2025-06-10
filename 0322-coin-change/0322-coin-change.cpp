class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
        
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                int take = 1e9;
                if(coins[i-1] <= j)
                {
                    take = 1 + dp[i][j-coins[i-1]];
                }
                int nottake = dp[i-1][j];

                dp[i][j] =  min(take,nottake);
            }
        }        

        int ans =  dp[n][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};