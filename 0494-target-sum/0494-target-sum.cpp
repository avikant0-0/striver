using ll = long long ;
class Solution {
public:
    ll maintarget;
    ll f(auto &nums,ll i , ll sum) {
        if( i == nums.size() ) {
            if(sum == maintarget) return 1;
            else return 0 ;
        }
        return f(nums,i+1,sum+nums[i]) + f(nums,i+1,sum-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        maintarget = target ;
        return f(nums,0,0);
    }
};