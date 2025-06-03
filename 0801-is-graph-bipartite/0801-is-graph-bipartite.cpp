class Solution {
public:
    bool bfs(int node,auto& a,auto& color)
    {
        queue<pair<int,int>> q;
        color[node] = 0;
        q.push({node,0});

        while(!q.empty())
        {
            pair<int,int> top = q.front();
            q.pop();

            for(int child : a[top.first])
            {
                if(color[child] == -1)
                {
                    q.push({child,!top.second});
                    color[child] = !top.second;
                }
                else if(color[child] == top.second) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> color(n,-1);

        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!bfs(i,a,color)) return false;
            }
        }

        return true;
    }
};