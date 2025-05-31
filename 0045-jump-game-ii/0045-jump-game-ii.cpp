class Solution {
public:
    vector<int> dp;
    int f(int i,auto& a){
        if(i >= a.size() - 1) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = 1e9;
        for(int j = 1; j <= a[i]; j++){
            ans = min(ans,1 + f(i+j,a));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& a) {
        dp.assign(a.size(),-1);
        return f(0,a);
    }
};