class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 1) return nums[0] ;
        vector<int> dp(n+1,-1);

        vector<int> arr(nums.begin()+1,nums.end());
        auto f = [&](int i,auto&& f)->int{
            if(i > arr.size() - 1) return 0;
            if(dp[i]!=-1) return dp[i];
            return dp[i] = max(arr[i]+f(i+2,f),f(i+1,f));
        };

        int ans1 = f(0,f);
        arr.erase(prev(arr.end()));
        arr.insert(arr.begin(),nums[0]);
        dp.assign(n+1,-1);
        int ans2 = f(0,f);

        return max(ans1,ans2) ;
    }
};