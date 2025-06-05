class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> edges, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        dist[src][0] = 0;

        priority_queue<tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                greater<tuple<int,int,int>>> q;

        q.push({0,0,src});

        while(!q.empty())
        {
            auto [dis,currk,node] = q.top();
            q.pop();
            if(node == dst) return dis;
            if(currk > k) continue;

            for(auto c : adj[node])
            {
                int child = c.first;
                int newDist = c.second;

                if(newDist + dis < dist[child][currk])
                {
                    dist[child][currk] = newDist + dis;
                    q.push(make_tuple(newDist+dis,currk+1,child));
                }
            }
        }

        return -1;
    }
};