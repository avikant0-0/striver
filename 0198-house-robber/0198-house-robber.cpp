class Solution {
public:
    vector<int> dp;
    int f(int i,vector<int>& a)
    {
        int n = a.size();
        if(i >= n ) return 0;

        if(dp[i] != -1) return dp[i];

        int curr = f(i+2,a) + a[i];
        int adj = f(i+1,a);

        return dp[i] = max(curr,adj);
    }
    int rob(vector<int>& a) {
        dp.assign(a.size(),-1);
        return f(0,a);
    }
};