using ll = long long;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
    deque <ll> q ;
    ll n = skills.size();
    map<ll,int> mp ;
    for(ll i = 0 ; i < n; i++ ) {
        mp[skills[i]] = i ; 
    }
    for(ll i =0 ; i < n ; i++ ) q.push_back(skills[i]) ;
    ll mx = *max_element(skills.begin(),skills.end()) ;
    ll count =0  ; 
    ll last = max(q[0],q[1]);
    for(ll i =0 ; i <  n; i++)  {
        ll t1 = q.front() ;
        q.pop_front();
        ll t2 = q.front() ;
        q.pop_front();
        if( t1 < t2 ) swap(t1,t2);

        if(t1 == last ) ++count;
        else count=1;
        if(count == k || t2 == mx ) {
            // cout<<mp[t1]<<endl;
            return mp[t1] ;
        }
        q.push_front(t1) ;
        q.push_back(t2);
        last = max(t2,t1);
}
    // cout<<mp[mx]<<endl;
    return mp[mx] ;
    }
};