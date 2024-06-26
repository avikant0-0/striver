class Solution {
public:
    vector<vector<vector<int>>> memo;
    
    int f(vector<int>& a, int pos, int k, int last) {
        if (k < 0) return 0;
        if (pos == a.size()) return 0;
        
        // Check if this state has been computed before
        if (last != -1 && memo[pos][k][last] != -1) {
            return memo[pos][k][last];
        }
        
        int take = 0;
        if (last == -1 || a[last] == a[pos]) take = 1 + f(a, pos+1, k, pos);
        else if (k > 0) take = 1 + f(a, pos+1, k-1, pos);
        
        int skip = f(a, pos+1, k, last);
        
        int result = max(skip, take);
        
        // Memoize the result
        if (last != -1) {
            memo[pos][k][last] = result;
        }
        
        return result;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // Initialize memoization table
        memo.assign(n, vector<vector<int>>(k+1, vector<int>(n, -1)));
        return f(nums, 0, k, -1);
    }
};