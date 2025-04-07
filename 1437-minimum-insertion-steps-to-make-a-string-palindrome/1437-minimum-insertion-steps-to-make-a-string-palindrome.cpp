class Solution {
public:

    vector<vector<int>> dp;
    int lcs(int i,int j,string& A){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    if(A[i] == A[j]) return dp[i][j] = 2 + lcs(i+1,j-1,A);
    else return dp[i][j] = max(lcs(i,j-1,A),lcs(i+1,j,A));
    }
    int minInsertions(string A) {
        int n = A.size();
        dp.assign(n,vector<int>(n+1,-1));
        return n - lcs(0,n-1,A);
    }
};