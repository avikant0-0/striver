class Solution {
public:

   
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int  i =0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j] = 1; 
                }
            }
        }

        while(!q.empty()){
            pair<pair<int,int>,int> front = q.front();
            q.pop();

            vector<int> dx = {0,0,-1,1};
            vector<int> dy = {1,-1,0,0};

            int si = front.first.first;
            int sj = front.first.second;
            int st = front.second;

            ans = max(ans,st); 

            for(int i1 = 0; i1 < 4; i1++){
                int ni = si + dx[i1];
                int nj = sj + dy[i1];
                if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj] == 1 && !visited[ni][nj]){
                    visited[ni][nj] = 1; 
                    grid[ni][nj] = 2;
                    q.push(make_pair(make_pair(ni,nj),st+1));
                }
            }
        }

        for(int  i =0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};