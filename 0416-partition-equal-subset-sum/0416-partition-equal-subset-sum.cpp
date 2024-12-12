using ll = long long ;
class Solution {
public:
    int target ;
    vector<vector<int>> dp;
    int f(auto &nums,int i,int sum){
        if(i == nums.size()) {
            if(sum == target) return dp[i][sum] = true;
            else return dp[i][sum] = false;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        if(sum + nums[i] <= target) return dp[i][sum] = f(nums,i+1,sum) || f(nums,i+1,sum+nums[i]) ; 
        else return dp[i][sum] = f(nums,i+1,sum) ; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        target = sum / 2;
        dp.assign(nums.size()+1,vector<int>(target+1,-1));
        return f(nums,0,0);
    }
};