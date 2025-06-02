class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int  n = a.size(),  m = a[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<vector<int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 0)
                {
                    q.push({i,j,0});
                    visited[i][j] = 1;
                }
            }
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {-1,1,0,0};

        while(!q.empty())
        {
            vector<int> top = q.front();
            q.pop();
            ans[top[0]][top[1]] = top[2];

            for(int i = 0; i < 4; i++)
            {
                int ni = top[0] + dx[i];
                int nj = top[1] + dy[i];

                if(ni<0 || ni >= n || nj < 0 || nj >= m) continue;

                if(a[ni][nj] == 0) continue;
                if(visited[ni][nj]) continue;

                visited[ni][nj] = 1;
                q.push({ni,nj,top[2]+1});
            }
        }

        return ans;
    }
};