class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> P(n),S(n);
        P[0] = height[0];
        for(int i = 1; i < n; i++){
            P[i] = max(height[i],P[i-1]);
        }
        S[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--){
            S[i] = max(S[i+1],height[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++){
            int curr = min(P[i-1],S[i+1]) - height[i];
            if(curr < 0) continue;
            ans += curr;
        }
        return ans ;
    }
};