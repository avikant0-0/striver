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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> mp;
        DisjointSet ds(accounts.size());
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else{
                    ds.unionByRank(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> ans(accounts.size());
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                int k = mp[accounts[i][j]];
                int ul_p_k = ds.findUPar(k);
                if(ans[ul_p_k].size() == 0) 
                    ans[ul_p_k].push_back(accounts[i][0]);

                ans[ul_p_k].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> finalAns;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].empty()) continue;

            sort(ans[i].begin() + 1, ans[i].end()); 
            ans[i].erase(unique(ans[i].begin() + 1, ans[i].end()), ans[i].end());
            finalAns.push_back(ans[i]);
        }
        return finalAns;
    }
};