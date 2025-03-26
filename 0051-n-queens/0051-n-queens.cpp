class Solution {
public:

    bool isSafe(int row,int col,auto& t){
        for(int i = col - 1; i >= 0; i--){
            if(t[row][i] == 'Q') return false; 
        }
        int i = row , j =  col; 
        while(i >= 0 && j >= 0){
            if(t[i][j] == 'Q') return false;
            --i,--j;
        }
        i = row, j = col;
        while(i < t.size() && j >= 0){
            if(t[i][j] == 'Q') return false;
            ++i,--j;
        }
        return true; 
    }
    void dfs(int col, auto t, auto& ans){
        if(col == t.size()){
            ans.push_back(t);
            return;
        }

        for(int row = 0 ; row < t.size(); row++){
            if(isSafe(row,col,t)){
                t[row][col] = 'Q';
                dfs(col+1, t,ans);
                t[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp ; 
        for(int i = 0; i < n; i++) temp += '.';
        vector<string> t(n,temp);

        dfs(0,t,ans); 

        return ans; 
    }
};