class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        vector <vector<int>> dp(n+1, vector<int> (n+1 , -1 )) ;
        for(int i = 0; i< n+1;i++){
            for(int j = 0; j <n+1;j++){
                if(i==0||j==0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1] ;
                else dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) ;
            }

        }
        return abs(dp[n][n] - n);
    }
};