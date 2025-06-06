class Solution {
public:
     class DisjointSet
{   
    public:
    vector<int> rank,parent,size;

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
    

    int largestIsland(vector<vector<int>>& a) {
        int n = a.size();
        DisjointSet ds(n*n);
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 0) continue;
                int node = i*n + j;
                for(int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue; 
                    if(a[ni][nj] == 0) continue;
                    int newNode = ni * n + nj;
                    ds.unionBySize(newNode,node);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                set<int> st;
                bool flag = 1;
                int node = i * n + j;

                for(int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    if(a[ni][nj] == 0) continue;
                    int newNode = ni * n + nj;
                    st.insert(ds.findUPar(newNode));
                    if(ds.findUPar(newNode) == ds.findUPar(node)) flag = 0;
                }
                int tempans = 0;
                for(int l : st) {
                    tempans += ds.size[l];
                    
                }
                if(flag) ++tempans;
               
                ans = max(ans,tempans);
            }
        }

        return ans;
    }
};