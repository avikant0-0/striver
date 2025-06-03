class Solution {
public:
    bool dfs(int k,int c,auto& a,auto& color)
    {
        color[k] = c;

        for(int child : a[k])
        {   
            if(color[child] == -1)
            {
                if(dfs(child,!c,a,color) == false) return false;
            }
            else if(color[child] == c) return false;
        }   

        return true;
    }
    bool isBipartite(vector<vector<int>>& a) 
    {   
        vector<int> color(a.size(), -1);
        for (int i = 0; i < a.size(); i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, a, color)) return false;
            }
        }
        return true;
    }
};