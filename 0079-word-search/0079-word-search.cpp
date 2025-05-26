class Solution {
public:
    vector<vector<int>> visited;
    bool f(int i,int j,int len,auto& a,auto& w){
        int n = a.size(), m = a[0].size();

        if(len == w.size()){
            return true; 
        }
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        if(a[i][j] != w[len]) return false;

        if(visited[i][j]) return false;
        visited[i][j] = 1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int ind = 0; ind <= 3; ind++){
            int n_i = i+dx[ind], n_j = j+dy[ind];

            if( f(n_i,n_j,len+1,a,w) ) return true;
        }
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& a, string w) {
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                visited.assign(a.size(),vector<int>(a[0].size(),0));

                if( f(i,j,0,a,w) ){
                    return true;
                }
            }
        }

        return false;
    }
};