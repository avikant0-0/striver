class Solution {
public:

    bool dfs(int node,int par,auto& visited,auto& pathVisited,auto& isSafe,auto& a)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(int child : a[node])
        {
            // if(child == par) continue;
            if(!visited[child])
            {
                if(dfs(child,node,visited,pathVisited,isSafe,a)){
                    isSafe[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[child])
            {   
                isSafe[node] = 0;
                return true;
            }
        }

        pathVisited[node] = 0;
        isSafe[node] = 1; 
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> visited(n,0), pathVisited(n,0),isSafe(n,0);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i,-1,visited,pathVisited,isSafe,a);
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if(isSafe[i]) res.push_back(i);
        }

        return res;
    }
};