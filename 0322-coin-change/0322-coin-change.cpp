class Solution {
public:
    vector<int> t;
    int f(auto &coins, int amount){
        if(amount < 0 ) return INT_MAX ;
        if(amount == 0) return 0;
        if(t[amount] != -1 ) return t[amount] ;
        int best = INT_MAX ; 
        for(auto i : coins) {
            int temp = f(coins, amount - i) ;
            if(temp != INT_MAX) 
            best = min(best , temp + 1) ;
        }
        return t[amount] = best ; 
    }
    int coinChange(vector<int>& coins, int amount) {
        t.assign(1e4+1 , -1 );
        int ans = f(coins, amount) ;
        return  ans != INT_MAX ? ans : -1 ;
    }
};