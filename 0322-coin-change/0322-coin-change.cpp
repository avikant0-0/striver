class Solution {
public:
    using ll = long long; 
    vector<ll> dp;
    ll f(auto &coins,ll amount){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount]!=-1)return dp[amount] ;
        ll ans = INT_MAX;
        for(auto c : coins) {
            ans = min(ans,f(coins,amount-c)+1);
        }
        dp[amount] = ans;
        return  ans;
    }

    ll coinChange(vector<int>& coins, ll amount) {
        dp.assign(amount+1,-1);
        ll ans =f(coins,amount) ;
        
        if(ans < INT_MAX) return ans;
        else return -1;
    }
};