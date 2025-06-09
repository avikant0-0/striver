class Solution {
public:

    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> up(m,vector<int>(m,INT_MIN));

        up[0][m-1] = (m-1 != 0 ? a[0][0] + a[0][m-1] : a[0][0]);

        for(int i = 1; i < n; i++)
        {   
            vector<vector<int>> temp(m,vector<int>(m,INT_MIN));
            for(int j1 = 0; j1 < m; j1++)
            {
                for(int j2 = 0; j2 < m; j2++)
                {
                    for(int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for(int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int nj1 = j1 + dj1, nj2 = j2 + dj2;
                            if(nj1 < 0 || nj2 < 0 || nj1 >= m || nj2 >= m) continue;
                            temp[j1][j2] = max(temp[j1][j2],up[nj1][nj2]+ (j1 == j2 ? a[i][j1] : a[i][j1] + a[i][j2]));
                        }
                    }
                }
            }
            up = temp;

        }
        int ans = INT_MIN;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
                ans = max(ans,up[i][j]);
        }
        return ans;
    }

    // O(10 * n * m * m + m * m)
    // O(m*m(1+10*n)) 
};