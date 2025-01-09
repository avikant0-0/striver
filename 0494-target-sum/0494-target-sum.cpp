class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        int tofind = (tsum + target) / 2;

        if( (tsum + target) % 2 != 0 || tofind < 0) return 0;
        
        vector<vector<int>> dp(nums.size(),vector<int> (tofind+1,-1));

        auto f = [&](int i,int T,auto&& f){
            if(i == -1) {
                if(T == 0) return 1;
                else return 0;
            }

            if(dp[i][T] != -1) return dp[i][T];

            int include = 0;
            if(T - nums[i] >= 0) include = f(i - 1, T - nums[i], f);
            int exclude = f(i-1,T,f);

            return dp[i][T] = include + exclude; 
        };

        return f(nums.size() - 1, tofind, f) ; 
    }
};