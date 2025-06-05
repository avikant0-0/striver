class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
        queue<tuple<int,int,int>> q;

        vector<vector<int>> visited(n,vector<int>(n,0));
        int ans = INT_MAX;
        if(a[0][0] == 0)
        {
            q.push(make_tuple(0,0,1));
            visited[0][0] = 1;
        } 

        while(!q.empty())
        {
            auto [oi,oj,steps] =  q.front();
            q.pop();
            if(oi == n - 1 && oj == n - 1) ans = min(ans,steps);

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {   
                    int ni = oi + i, nj = oj + j;
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    if(a[ni][nj] == 1) continue;
                    if(visited[ni][nj]) continue;
    
                    visited[ni][nj] = 1;
                    q.push(make_tuple(ni,nj,1+steps));
                }
            }
        }

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};