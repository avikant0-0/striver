class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size() , n = a[0].size() ;


        int left = 1;
        vector<int> up(n+1,0);
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {   
            vector<int> temp(n+1,0);
            for(int j = 1; j <= n; j++)
            {   
                if(a[i-1][j-1] == 1)
                {
                    ans = 0;
                    left = ans;
                    temp[j] = ans;
                }
                else
                {
                    ans = left + up[j];
                    left = ans;
                    temp[j] = ans;
                }
            }
            left = 0;
            up = temp;
        }
        return ans;
    }
};