class Solution {
public:
    class DisjointSet
{
    vector<int> rank,parent,size;
    public:

    DisjointSet(int n)
    {
        rank.assign(n+1,0);
        parent.assign(n+1,0);
        for(int i = 0; i < n + 1; i++)
            parent[i] = i;
        size.assign(n+1,1);
    }

    int findUPar(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u,int v)
    {
        int ul_p_u = findUPar(u);
        int ul_p_v = findUPar(v);

        if(ul_p_u == ul_p_v) return;
        
        if(rank[ul_p_u] < rank[ul_p_v])
            parent[ul_p_u] = ul_p_v;
        
        else if(rank[ul_p_u] > rank[ul_p_v])
            parent[ul_p_v] = ul_p_u;
        
        else{
            parent[ul_p_u] = ul_p_v;
            rank[ul_p_v]++; 
        }
    }

    void unionBySize(int u,int v)
    {
        int ul_p_u = findUPar(u);
        int ul_p_v = findUPar(v);

        if(ul_p_u == ul_p_v) return;

        if(size[ul_p_u] < size[ul_p_v])
        {
            parent[ul_p_v] = ul_p_u;
            size[ul_p_u] += size[ul_p_v];
        }
        else
        {
            parent[ul_p_u] = ul_p_v;
            size[ul_p_v] += size[ul_p_u];
        }
    }
};  
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int extra = 0,connected = 0;
        for(auto it : edges)
        {
            int u = it[0], v = it[1];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionByRank(u,v);
                ++connected;
                continue;
            }
            ++extra;
        }
        if(extra >= n - 1 - connected) return n - 1 - connected;
        else return -1;
    }
};