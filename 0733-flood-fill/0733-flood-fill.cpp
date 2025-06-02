class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        queue<vector<int>> q;
        int n = a.size(), m = a[0].size();

        q.push({sr,sc});
        vector<vector<int>> visited(n,vector<int>(m,0));

        visited[sr][sc] = 1;
        int org = a[sr][sc];
        a[sr][sc] = color;


        while(!q.empty())
        {   

            vector<int> top = q.front();
            q.pop();

            int dx[] = {0,0,1,-1};
            int dy[] = {-1,1,0,0};

            for(int i = 0; i < 4; i++)
            {
                int ni = top[0] + dx[i];
                int nj = top[1] + dy[i];

                if(ni >=0 && ni < n && nj >= 0 && nj < m)
                {
                    if(!visited[ni][nj] && a[ni][nj] == org)
                    {   
                        q.push({ni,nj});
                        a[ni][nj] = color;
                        visited[ni][nj] = 1;
                    }
                }
            }
        }

        return a;
    }
};