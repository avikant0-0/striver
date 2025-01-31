class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> S(n);
        int P = height[0];

        S[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--){
            S[i] = max(S[i+1],height[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++){
            int curr = min(P,S[i+1]) - height[i];
            P = max(P,height[i]);
            if(curr < 0) continue;
            ans += curr;
        }
        return ans ;
    }
};