class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int i = 0, j = 0;

        int zeros = 0, ans = 0;

        while( j <= n ){
            if(j == n){
                if(zeros <= k) ans = max(ans,j-i);
                break;
            }
            
            zeros += a[j] == 0;

            if(a[j] == 1 && zeros <= k){
                ans = max(ans,j-i+1);
                ++j;
            }else{
                if(zeros <= k){
                    ans = max(ans,j-i+1);
                    ++j;
                }
                else {
                    if(a[i] == 0) --zeros;
                    ++i;
                    ++j;
                }
            }
        }
        return ans;
    }
};
