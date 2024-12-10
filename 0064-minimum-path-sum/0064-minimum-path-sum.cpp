class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
         int n = a.size() , m = a[0].size() ;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        auto f = [&](int i,int j,auto&& f)->long long{
            if(i > n || j > m) return INT_MAX;
            if(i == n && j == m) return a[i-1][j-1];

            if(dp[i][j] != -1) return dp[i][j]; 

            return dp[i][j] = a[i-1][j-1] + min(f(i+1,j,f) , f(i,j+1,f));
        };

        return f(1,1,f);
    }
};