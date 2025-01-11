class Solution {
public:

    void BFS(int sourceNode,vector<vector<int>>&
        adj, vector<int>& visited){

        queue<int> q;
        
        q.push(sourceNode);
        visited[sourceNode] = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop(); 
            
            
            for(int i = 0; i < adj[0].size() ; i++){
                if(adj[front][i] == 1 && !visited[i]){
                    visited[i] = 1; 
                    q.push(i);
                }
            }
            
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n =isConnected.size();
        vector<int> visited(n,0);

        for(int  i =0; i < n; i++) {
            if(!visited[i]){
                ++ans;
                BFS(i,isConnected,visited);
            }
        }
        return ans;
    }
};