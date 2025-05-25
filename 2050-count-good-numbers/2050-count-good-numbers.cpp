class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    ll f(ll m,ll N){
        if(N == 0) return 1;
        if(N == 1) return m;

       if(N % 2 == 0) return f( ((m % mod )* (m % mod) )% mod,N/2);
       else return ((m % mod) * f(m % mod ,N-1)) % mod;
    }
    int countGoodNumbers(ll n) {
        ll even = (n+1)/2;
        ll odd = n / 2;

        return ((f(5,even) % mod )* (f(4,odd) % mod) ) % mod;
    }
};