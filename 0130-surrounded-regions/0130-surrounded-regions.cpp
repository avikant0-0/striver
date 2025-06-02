class Solution {
public:
    void bfs(int i,int j,char toR,auto& a)
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
                if(a[ni][nj] == 'O')
                {
                    a[ni][nj] = toR;
                    q.push({ni,nj});
                }
            }
        }

    }
    void solve(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if(a[i][j] == 'O')
                    {   
                        bfs(i,j,'-',a);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                if(a[i][j] == 'O')
                {
                    bfs(i,j,'X',a);
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                if(a[i][j] == '-')
                {
                    a[i][j] = 'O';
                }
            }
        }

    }
};