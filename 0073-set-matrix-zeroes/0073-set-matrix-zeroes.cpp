class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int col = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0){
                    if(a[i][j] == 0) col = -159,a[i][0] = -159;
                }
                else if(a[i][j] == 0) a[0][j] = -159, a[i][0] = -159;
            }
        }
        for(int i = 1; i < n; i++){
            if(a[i][0] == -159){
                for(int j = 0; j < m; j++) a[i][j] = 0;
            }
        }
        for(int j = 1; j < m; j++){
            if(a[0][j] == -159){
                for(int i = 0; i < n;i++) a[i][j] = 0;
            }
        }
        if(a[0][0] == -159){
            for(int j = 0; j < m; j++) a[0][j] = 0;
        }
        // cout << col << endl;
        if(col == -159){
            for(int i = 0; i < n; i++) a[i][0] = 0;
        }
    }
};