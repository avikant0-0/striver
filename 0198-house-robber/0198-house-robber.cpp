class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> dp(a.size(),0);
        dp[0] = a[0];
        dp[1] = max(a[0],a[1]);

        for(int i = 2; i < a.size(); i++)
        {
            dp[i] = max(dp[i-2] + a[i] , dp[i-1]);
        }
        return dp[a.size()-1];
    }
};