class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<vector<int>> q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1) ++cnt;
                if(a[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] = 1;
                }
            }
        }

        int ans = 0;
        while(!q.empty()){
            vector<int> top = q.front();
            q.pop();

            int dx[] = {0,0,-1,1};
            int dy[] = {1,-1,0,0};
            ans = max(ans,top[2]);

            for(int i = 0; i < 4; i++){
                int ni = top[0] + dx[i];
                int nj = top[1] + dy[i];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && a[ni][nj] != 0){
                    visited[ni][nj] = 1;
                    q.push({ni,nj,top[2]+1});
                    --cnt;
                    a[ni][nj] = 2;
                }
            }
        }
        return (cnt > 0 ? -1 : ans);
    }
};