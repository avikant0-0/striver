class Solution {
public:
    vector<int> visited;
    void dfs(int k,auto& a){
        if(visited[k]) return;
        visited[k] = 1;
        for(int i = 0; i < a.size(); i++){
            if(a[k][i] == 1 && k != i){
                dfs(i,a);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        visited.assign(n,0);
        for(int i =0 ; i < n; i++){
            if(!visited[i]){
                dfs(i,a);
                ++ans;
            }
        }
        return ans;
    }
};