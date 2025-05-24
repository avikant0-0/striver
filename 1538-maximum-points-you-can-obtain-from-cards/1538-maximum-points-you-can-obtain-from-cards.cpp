class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> p(n),s(n);

        int ans = 0;

        for(int i = 0; i < n; i++){
            p[i] = a[i] + ( i - 1 >= 0 ? p[i-1]  : 0 );
        }

        for(int i = n - 1; i >= 0; i--){
            s[i] = a[i] + (i + 1 < n ? s[i+1] : 0 );
        }

        for(int i = 0; i <= k; i++){
            int tempans = 0;
            tempans += (i - 1 >= 0 ? p[i-1] : 0);
            tempans += (n - k + i < n ? s[n-k+i] : 0);
            ans = max(ans,tempans);
        }

        return ans;
    }
};