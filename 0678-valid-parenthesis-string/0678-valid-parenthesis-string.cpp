class Solution {
public:
    int n;
    vector<vector<int>> dp;
    bool f(string s,int i,int j){
        if(j < 0) return false;
        if(i==s.size()){
            if(j == 0) return true;
            else return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == '(') return dp[i][j] = f(s,i+1,j+1);
        else if(s[i] == ')') return dp[i][j] = f(s,i+1,j-1);
        else return dp[i][j] = (f(s,i+1,j+1) || f(s,i+1,j-1) || f(s,i+1,j));
    }
    bool checkValidString(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return f(s,0,0);
    }
};