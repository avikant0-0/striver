class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edge) {
        vector<vector<int>> adj(V,vector<int>());
        vector<int> indegree(V,0);
        for(auto it : edge)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }  

        queue<int>  q;

        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            res.push_back(front);

            for(int child : adj[front])
            {
                indegree[child]--;
                if(indegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        if(res.size() != V) return {};
        else return res;
    }
};