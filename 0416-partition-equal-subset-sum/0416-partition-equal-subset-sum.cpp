using ll = long long;

class Solution {
public:
    ll targetsum;
    vector<vector<ll>> dp;
    bool solve(auto &nums, ll i , ll sum ) {
        if(i == ll(nums.size())) {
            if(sum == 0 ) return true;
            else return false;
        }
        if(dp[i][sum] != -1 ) return dp[i][sum];
        if(nums[i] <= sum ) {
            ll donttake = solve(nums,i+1,sum);
            ll take = solve(nums,i+1,sum - nums[i]) ;
            return  dp[i][sum] = donttake || take ;
        }
        else return  dp[i][sum] = solve(nums,i+1,sum) ;
        
    }
    bool canPartition(vector<int>& nums) {
    ll n = nums.size();
    targetsum = accumulate(nums.begin(),nums.end(),0) ;
    dp.assign(n+1,vector<ll>(targetsum +1 , -1)) ;
    
    if(targetsum % 2 != 0) return false;
    return solve(nums,0,targetsum / 2) ;    
    }
};