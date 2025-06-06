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

    int components(){
        map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < parent.size(); i++){
             findUPar(i);
        }
        
        for(int i : parent)  mp[i]++;

        for(auto [l,r] : mp) {
            if(r > 1) ++ans;
        }
        return ans;
    }
};  
    int removeStones(vector<vector<int>>& edges) {
        int n = edges.size(), maxRow = INT_MIN,maxCol = INT_MIN;
        for(auto it : edges)
        {
            int i = it[0], j = it[1];
            maxRow = max(maxRow,i);
            maxCol = max(maxCol,j);
        }
        DisjointSet ds(maxRow+maxCol+1);
        for(auto it : edges)
        {
            int i = it[0], j = it[1];
            // cout << i <<" " << j + maxRow + 1 << endl;
            ds.unionByRank(i,j+maxRow+1);
        }
        return n - ds.components();
    }
};