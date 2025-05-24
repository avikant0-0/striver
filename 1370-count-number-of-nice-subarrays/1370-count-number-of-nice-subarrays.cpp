class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int odd = 0;
        int ans =0 ;
        for(int i = 0; i < n; i++){
            odd += (a[i] % 2);

            if(mp.find(odd-k) != mp.end()) ans += mp[odd-k];

            mp[odd]++;
        }

        return ans;
    }
};