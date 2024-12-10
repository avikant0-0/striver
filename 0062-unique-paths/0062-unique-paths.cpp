class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        auto f = [&](int i,int j,auto&& f)->long long{
            if(i > n || j > m) return 0;
            if(i == n && j == m) return 1;

            if(dp[i][j] != -1) return dp[i][j]; 
            return dp[i][j] = f(i+1,j,f) + f(i,j+1,f);
        };

        return f(1,1,f);
    }
};