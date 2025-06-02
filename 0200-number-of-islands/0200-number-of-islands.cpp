class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(int i,int j,vector<vector<int>> &visited,auto& a,int n,int m)
    {
        visited[i][j] = 1;

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            if(visited[ni][nj] || a[ni][nj] == '0') continue;

            dfs(ni,nj,visited,a,n,m);
        }
    }
   
    int numIslands(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && a[i][j] == '1')
                {
                    ++ans;
                    dfs(i,j,visited,a,n,m);
                }
            }
        }

        return ans;
    }
};