using ll = long long ;
class Solution {
public:
    ll target ;
    vector<vector<ll>> dp;
    ll f(auto &nums,ll i,ll sum){
        if(i == nums.size()) {
            if(sum == target) return dp[i][sum] = true;
            else return dp[i][sum] = false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = f(nums,i+1,sum) || f(nums,i+1,sum+nums[i]) ; 
    }
    bool canPartition(vector<int>& nums) {
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum%2 != 0) return false;
        dp.assign(nums.size()+1,vector<ll>(2*sum+1,-1));
        target = sum / 2;
        return f(nums,0,0);
    }
};