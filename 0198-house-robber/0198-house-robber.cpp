class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);

        auto f = [&](int i,auto&& f)->int{
            if(i >= n) return 0; 

            if(dp[i]!= -1) return dp[i];
            int ans1 = INT_MIN;
            
            ans1 = max(nums[i] + f(i+2,f) , f(i+1,f));
            return dp[i] = ans1;
        };

        return f(0,f); 
    }
};