class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int l = 0, r = a.size() * a[0].size() - 1;
        while( l <= r ){
            int mid = midpoint(l,r);
            int row = mid / a[0].size();
            int col = mid % a[0].size();

            if(a[row][col] <= t) l = mid + 1;
            else r = mid - 1;
        }
        return r >= 0 ? a[r/a[0].size()][r%a[0].size()] == t : false;
    }
};