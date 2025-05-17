class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size();
        long long N = n * m;
        long long curr_sum = 0, sum = N * ( N + 1 ) / 2;
        long long curr_sum_sq = 0, sum_sq = (N * ( N + 1 ) * ( 2 * N + 1) )/ 6;

        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                curr_sum += grid[i][j];
                curr_sum_sq += grid[i][j] * grid[i][j];
            }
        }
        cout << curr_sum <<" " << sum <<" " << curr_sum_sq <<" " <<sum_sq << endl;
        vector<int> ans(2);
        long long a_b = curr_sum - sum;
        long long aplusb = (curr_sum_sq - sum_sq) / a_b;
        ans[0] = (a_b + aplusb)/2;
        ans[1] = ans[0] - a_b;
        return ans;    
    }
};