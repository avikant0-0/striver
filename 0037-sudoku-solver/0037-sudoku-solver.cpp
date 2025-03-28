class Solution {
public:
    bool isSafe(int n,int row,int col,auto& board){
        for(int i = 0; i < 9; i++){
            if((board[row][i] == n + '0') || (board[i][col] == n + '0')) return false;
        }

        int row1 = row / 3;
        int col1 = col / 3;

        for(int i = (3*row1); i < 3*row1 + 3 ; i++){
            for(int j = 3*col1; j < 3*col1 + 3; j++){
                if(board[i][j] == (n + '0')) return false;
            }
        }
       

        return true;
    }
    bool dfs(int row,auto& board){
        int n = board.size();
        if(row == n){
            return true;
        }

        for(int col = 0; col < n; col++){
            if(board[row][col] != '.') continue;
            for(int j = 1; j <= 9; j++){
                if(isSafe(j,row,col,board)){
                    board[row][col] = (j+'0');
                    if(col == n - 1) {
                        if(dfs(row+1,board)) return true;
                    }
                    else{
                        if( dfs(row,board) ) return true;
                    }
                    board[row][col] = '.';
                }
            }
            return false;
        }

        return dfs(row+1,board); 
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(0,board);
    }
};