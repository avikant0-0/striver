class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        int mx = a[n-1];
        for(int i = n - 1; i >= 0; i--){
           
            ans = max(ans,mx-a[i]);
            mx = max(mx,a[i]);
        }
        return ans;
    }
};