class Solution {
public:
    vector<int> visited;
    void bfs(int k,auto& a){
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int top = q.front();
            q.pop();
            visited[top] = 1;

            for(int i = 0; i < a.size(); i++){
                if(a[top][i] == 1 && !visited[i]){
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        visited.assign(n,0);
        for(int i =0 ; i < n; i++){
            if(!visited[i]){
                bfs(i,a);
                ++ans;
            }
        }
        return ans;
    }
};