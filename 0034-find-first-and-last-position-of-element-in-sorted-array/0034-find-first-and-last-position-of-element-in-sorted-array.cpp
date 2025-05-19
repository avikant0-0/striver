class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int ind1 = lower_bound(a.begin(),a.end(),t)-a.begin();
        if(ind1 == a.size() || a[ind1] != t) return {-1,-1};
        int ind2 = upper_bound(a.begin(),a.end(),t)-a.begin();
        return {ind1,ind2-1};
    }
};