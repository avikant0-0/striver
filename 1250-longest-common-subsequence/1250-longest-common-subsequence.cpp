class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        auto f = [&](int i,int j,auto&& f)->int{
            if(i < 0 || j < 0) return 0;

            if(dp[i][j] != -1) return dp[i][j]; 

            if(text1[i] == text2[j]) return dp[i][j] =  1 + f(i-1,j-1,f);
            else return dp[i][j] = max(f(i,j-1,f),f(i-1,j,f));
        };

        return f(n-1,m-1,f);
    }
};