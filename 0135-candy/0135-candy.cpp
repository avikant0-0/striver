class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<int> l(n),r(n);
        for(int i = 0; i < n; i++){
            if(i == 0) {
                l[0] = 1;
                continue;
            }
            if(a[i] > a[i-1]){
                l[i] = 1 + l[i-1];
            }
            else{
                l[i] = 1;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(i == n-1) {
                r[n-1] = 1;
                continue;
            }
            if(a[i] > a[i+1]){
                r[i] = 1 + r[i+1];
            }
            else{
                r[i] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans += max(l[i],r[i]);
        return ans;
    }
};