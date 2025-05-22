class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int l = 0, r = a.size() - 1;
        while( l <= r ){
            int mid = midpoint(l,r);
            if( a[mid][0] <= t ) l = mid + 1;
            else r = mid - 1;
        }

        return r >= 0 ? binary_search(a[r].begin(),a[r].end(),t) : false;
    }
};