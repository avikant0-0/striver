class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i,int j1,int j2,auto& a)
    {
        int n = a.size(), m = a[0].size();
        
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return INT_MIN;
        
        if(i >= n)
        {
            return 0;
        }

        if(dp[i][j1][j2] != INT_MIN) return dp[i][j1][j2];
    
        int ans = INT_MIN;
        
        for(int dj1 = -1; dj1 <= 1; dj1++)
        {
            for(int dj2 = -1; dj2 <= 1; dj2++)
            {
                int nj1 = j1 + dj1, nj2 = j2 + dj2;
                ans = max(ans,f(i+1,nj1,nj2,a));
            }
        }
        return dp[i][j1][j2] = ans + (j1 == j2 ? a[i][j1] : a[i][j1] + a[i][j2]);
    }
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(m,INT_MIN)));
        return f(0,0,m-1,a);
    }
};