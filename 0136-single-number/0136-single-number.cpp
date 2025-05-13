class Solution {
public:
    int singleNumber(vector<int>& a) {
        int ans = 0;
        for(int i : a) ans = ans ^ i;
        return ans;
    }
};