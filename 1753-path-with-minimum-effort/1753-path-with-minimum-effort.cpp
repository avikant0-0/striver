class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        priority_queue<tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> q;

        q.push(make_tuple(0,0,0));

        dist[0][0] = 0;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty())
        {
            auto [mx,oi,oj] = q.top();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int ni = oi + dx[i], nj = oj + dy[i];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                int newstep = max(mx,abs(a[ni][nj] - a[oi][oj]));
                if(newstep < dist[ni][nj])
                {
                    dist[ni][nj] = newstep;
                    q.push(make_tuple(newstep,ni,nj));
                }
            }
        }

        return dist[n-1][m-1];
    }
};