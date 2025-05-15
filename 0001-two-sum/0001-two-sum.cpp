class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        map<int,int> mp;
        for(int i = 0; i < a.size(); i++){
            if(mp[t-a[i]]) return {i,mp[t-a[i]]-1};
            mp[a[i]] = i + 1;
        }
        return {-1,-1};
    }
};