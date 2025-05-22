class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n = a.size(), m = a[0].size();
        int row = n - 1, col = 0;
        while(row >= 0 && col < m){
            if(a[row][col] == t) return true;
            else if(a[row][col] > t) row--;
            else col++;
        }
        return false;
    }
};