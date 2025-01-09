class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        int tofind = (tsum + target) / 2;

        if( (tsum + target) % 2 != 0 || tofind < 0) return 0;
        
        // vector<vector<int>> dp(nums.size(),vector<int> (tofind+1,0));
        vector<int> prev(tofind+1,0);

        // for(int i = 0; i < nums.size(); i++) dp[i][0] = 1;

        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1 ;

        if(nums[0] != 0 && nums[0] <= tofind) prev[nums[0]] = 1; 

        for(int i = 1; i < nums.size(); i++)
        {   
            vector<int> curr(tofind + 1,0);
            for(int T = 0; T <= tofind; T++)
            {
                int exclude = prev[T];

                int include = 0 ;
                if(T - nums[i] >= 0) include = prev[T-nums[i]];

                curr[T] = exclude + include ;
            }
            prev = curr;
        }

        return prev[tofind] ; 
    }
};