class Solution {
public:
    vector<int> visited;
    bool bfs(int k,auto& adj){
        queue<int> q;
        q.push(k);
        int v = 0, e = 0;
        visited[k] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ++v;

            for(int i : adj[top]){
                ++e;

                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        e/=2;
        return v*(v-1)/2 == e;
    }
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        visited.assign(n,0);
        vector<vector<int>> adj(n,vector<int>());

        for(int i = 0; i < e.size(); i++){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(bfs(i,adj))  ++ans;
            }
        }
        return ans;
    }
};