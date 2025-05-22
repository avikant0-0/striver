class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        for(int i = 0; i < a.size(); i++){
            if(t >= a[i][0] && t <= a[i].back()){
                return binary_search(a[i].begin(),a[i].end(),t);
            }
        }
        return false;
    }
};