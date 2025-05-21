class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size(), l = 0, r = 1e9;
        while( l <= r ){
            int mid = midpoint(l,r);
            int missing = mid - (lower_bound(a.begin(),a.end(),mid) - a.begin());
            if(missing <= k) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};