class Solution {
public:
    vector<vector<int>> dp;
    int f(auto &s,auto &t,int m,int n){
        if(m < 0 || n < 0) return 0; 
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m]==t[n]) return dp[m][n] = 1 + f(s,t,m-1,n-1);
        else return dp[m][n] = f(s,t,m,n-1);
    }
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp.assign(m,vector<int>(n,-1));
        if(m > n) return false;
        return f(s,t,m-1,n-1) == m; 
    }
};