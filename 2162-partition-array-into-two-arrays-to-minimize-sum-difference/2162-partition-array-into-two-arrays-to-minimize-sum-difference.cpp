using ll = long long ;
class Solution {
public:
    
    vector<vector<ll>> a,b;
    ll n ;
    void meetinmiddle1(auto &nums,ll i,ll taken,ll sum){
        if(i == n) {
            a[taken].push_back(sum);
            return ;
        }
        meetinmiddle1(nums,i+1,taken+1,sum+nums[i]);
        meetinmiddle1(nums,i+1,taken,sum);
    }
    void meetinmiddle2(auto &nums,ll i,ll taken,ll sum){
        if(i == 2*n) {
            b[taken].push_back(sum);
            return ;
        }
        meetinmiddle2(nums,i+1,taken+1,sum+nums[i]);
        meetinmiddle2(nums,i+1,taken,sum);
    }
    ll find_first_false(ll l ,ll r, auto f) {
        // --l ; ++r;
        while( r - l > 1 ){
           ll m = r + (l - r) / 2 ; ;
            if(f(m)) l = m ;
            else r = m;
        } 
        return l; 
    }

    int minimumDifference(vector<int>& nums) {
        n = nums.size() / 2 ;
        a.assign(n+1,vector<ll>());
        b.assign(n+1,vector<ll>());
        meetinmiddle1(nums,0LL,0LL,0LL);
        meetinmiddle2(nums,n,0LL,0LL);
      
        for(auto &j : b) sort(j.begin(),j.end());
        ll mindiff = LLONG_MAX;
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        for(ll i =0 ; i <= n ; i++) {
            for(ll j : a[i]) {
                ll target = sum / 2 - j ;

                ll k = find_first_false(0,b[n-i].size(),[&](ll mid){
                    return b[n-i][mid] <= target;
                });
                mindiff = min(mindiff,abs(sum-2*(b[n-i][k]+j)));
            }
        }
        return mindiff ; 
    }
};