class Solution {
public:
    int BFS(int src, int k,auto& adj)
    {   
        int n = adj.size();
        vector<int> dist(n,1e9);
        dist[src] = 0;

        priority_queue<tuple<int,int>,
                    vector<tuple<int,int>>,
                    greater<tuple<int,int>>> q;

        q.push({0,src});

        while(!q.empty())
        {
            auto [dis,node] = q.top();
            q.pop();

            if(dis > k) continue;

            for(auto c : adj[node])
            {
                int child = c.first,edgeWt = c.second;
                if(dis + edgeWt < dist[child])
                {
                    dist[child] = dis + edgeWt;
                    q.push({dist[child],child});
                }
            }
        }

        int res1 = 0;
        for(int i : dist)
            res1 += (i <= k);

        return res1 - 1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        int res = INT_MAX, city = -1;

        for(int i = 0; i < n; i++)
        {
            int res1 = BFS(i,k,adj);
            // cout << res1 << endl;
            if(res1 <= res)
            {   
                res = res1;
                city = i;
            }
        }

        return city;
    }
};