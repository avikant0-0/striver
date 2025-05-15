class Solution {
public:

    int find_cross(int i,int mid,int j,vector<int>& a){
        int left = 0;
        int left_max = INT_MIN;
        for(int it = mid; it >= i; it--){
            left += a[it];
            left_max = max(left_max,left);
        }
        int right = 0;
        int right_max = INT_MIN;
        for(int it = mid+1; it <= j; it++){
            right += a[it];
            right_max = max(right_max,right);
        }
        return left_max + right_max;
    }
    int dfs(int i,int j,vector<int>& a){
        if(i == j) return a[i];
        int mid = (i+j)/2;
        int left = dfs(i,mid,a);
        int right = dfs(mid+1,j,a);

        int cross = find_cross(i,mid,j,a);

        return max({cross,left,right});
    }
    int maxSubArray(vector<int>& a) {
        return dfs(0,a.size()-1,a);
    }
};