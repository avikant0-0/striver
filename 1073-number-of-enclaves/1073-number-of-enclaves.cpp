class Solution {
public:
    void bfs(int i,int j,int toR,auto& a)
    {   
        int n = a.size(), m = a[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        a[i][j] = toR;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty())
        {
            pair<int,int> top = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int ni = top.first + dx[i];
                int nj = top.second + dy[i];

                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(a[ni][nj] == 1)
                {
                    a[ni][nj] = toR;
                    q.push({ni,nj});
                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if(a[i][j] == 1)
                    {   
                        bfs(i,j,2,a);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans += a[i][j] == 1;
            }
        }
        return ans;
    }
};