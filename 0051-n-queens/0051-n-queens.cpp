class Solution {
public:

    bool isSafe(int row,int col,auto& t,auto& ub,auto& lb){
        for(int i = col - 1; i >= 0; i--){
            if(t[row][i] == 'Q') return false; 
        }
        if(ub[row-col+t.size()-1]) return false;
        if(lb[row+col]) return false;

        return true; 
    }
    void dfs(int col, auto t, auto& ans,auto ub, auto lb){
        if(col == t.size()){
            ans.push_back(t);
            return;
        }

        for(int row = 0 ; row < t.size(); row++){
            if(isSafe(row,col,t,ub,lb)){
                ub[row-col+t.size()-1] = 1;
                lb[row+col] = 1;
                t[row][col] = 'Q';

                dfs(col+1, t,ans,ub,lb);

                t[row][col] = '.';
                ub[row-col+t.size()-1] = 0;
                lb[row+col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp ; 
        for(int i = 0; i < n; i++) temp += '.';
        vector<string> t(n,temp);
        
        vector<bool> ub(2*n+1),lb(2*n+1);
        dfs(0,t,ans,ub,lb); 

        return ans; 
    }
};