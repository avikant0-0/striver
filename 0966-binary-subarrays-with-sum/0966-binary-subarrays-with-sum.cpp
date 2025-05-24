class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int g) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0,n = a.size(),psum = 0;
        for(int i = 0; i < n; i++){
            psum += a[i];
            
            ans += mp[psum - g];

            mp[psum]++;
        }

        return ans;
    }
};