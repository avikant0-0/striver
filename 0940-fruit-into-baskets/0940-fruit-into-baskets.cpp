class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        int ans = 0;
        vector<int> type(n);
        int sz = 0;

        while(j < n){
            if(type[a[j]] == 0) {
                ++sz;
            }

            type[a[j]]++;


            if(sz <= 2){
                ans = max(ans,j-i+1);
                ++j;
            }
            else{
                while(sz > 2){
                    type[a[i]]--;
                    if(type[a[i]] == 0)sz--;
                    ++i;
                }
                ans = max(ans,j-i+1);
                ++j;
            }
        }

        return ans;
    }
};