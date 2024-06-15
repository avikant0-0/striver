using ll = long long ;
#include<bits/stdc++.h>

class Solution {
public:
    ll maintarget;
    vector<vector<ll>> dp;
    ll offset = 0;
    ll f(auto &nums,ll i , ll sum) {
        if( i == nums.size() ) {
            if(sum == maintarget) return 1;
            else return 0 ;
        }
        if(dp[i][sum+offset] != -1 ) return dp[i][sum+offset];
        return dp[i][sum+offset] = f(nums,i+1,sum+nums[i]) + f(nums,i+1,sum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        maintarget = target ;
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        for(int i =0 ; i < nums.size(); i++ ) offset += abs(nums[i]) ; 
        dp.assign(nums.size()+1,vector<ll>(10000,-1));
        return f(nums,0,0);
    }
};