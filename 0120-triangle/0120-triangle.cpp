class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();

        int dp[n+1][a[n-1].size()+1];
        memset(dp,-1,sizeof(dp));

        auto f = [&](int i,int j,auto&& f)->int{
            if(i > n || j > a[i-1].size() ) return INT_MAX;
            if(i == n) return a[i-1][j-1];

            if(dp[i][j] != -1) return dp[i][j] ; 

            return dp[i][j] = a[i-1][j-1] + min(f(i+1,j+1,f) , f(i+1,j,f));
        };

        return f(1,1,f) ; 
    }
};