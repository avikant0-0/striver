class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long n = coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));

        for(long long i = 0 ; i < n; i++) dp[i][0] = 1; 

        for(long long i = 0; i < n; i++)
        {
            for(long long A = 1; A <= amount; A++)
            {
                long long exclude = ( i - 1 >= 0 ? dp[i-1][A] : 0 );
                long long include = 0 ;

                if(A - coins[i] >= 0) include = dp[i][A-coins[i]] ;

                dp[i][A] = include + exclude; 

                if (dp[i][A] > INT_MAX) {
                    dp[i][A] = INT_MAX;  // Cap the value to prevent overflow
                }
            }
        }
        // auto f = [&](long long i,int A,auto&& f)->int{
        //     if(A == 0) return 1; 
        //     if(i < 0 ) return 0; 
            

        //     int exclude = f(i-1,A,f);
        //     int include = 0;


        //     if(A - coins[i] >= 0) include =  f(i,A-coins[i],f);

        //     return exclude + include ;  
        // };

        return dp[n-1][amount];
    }
};