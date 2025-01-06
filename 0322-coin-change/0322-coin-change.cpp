class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1 , -1);

        auto f = [&](int amount,auto&& f)->long long{
            if(amount == 0) return 0;

            if(dp[amount] != -1) return dp[amount];

            long long ans = INT_MAX;

            for(auto c : coins){
                if(amount - c >= 0) ans = min(ans, 1 + f(amount - c,f));
                // else return ans = min(ans,f(amount,f));
            }

            return dp[amount] = ans; 
        };

        return f(amount,f) >= INT_MAX ? -1 : f(amount,f);
    }
};