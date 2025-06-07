class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int ones = 0;
            int n = i;

            while(n > 0)
            {
                n = (n&(n-1));
                ++ones;
            }
            ans.push_back(ones);
        }
        return ans;
    }
};