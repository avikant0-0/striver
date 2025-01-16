class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1; 


        int n = grid.size();
        int ans = INT_MAX; 
        queue<pair<pair<int,int>,int>> q;
        q.push(make_pair(make_pair(0,0),1));

        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = true; 

        while(!q.empty()){
            auto [x,y] = q.front().first;
            int curr_dist = 	q.front().second; 
            if(x == n- 1 && y == n -1 ) ans = min(ans,curr_dist); 
            q.pop();
            
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(x + i >= 0 && y + j >= 0 && x + i < n && y + j < n 
                    && !visited[x+i][y+j]  && grid[x+i][y+j] == 0){
                        visited[x+i][y+j] = 1; 
                        q.push(make_pair(make_pair(x+i,y+j),curr_dist+1));
                    }
                }
            }

            
        }
        if(visited[n-1][n-1] == 1) return ans;
		else return -1; 
    }
};