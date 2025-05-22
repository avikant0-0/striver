class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int zeroCount = 0;

        int i = 0, j = 0;
        int ans = 0;

        while (j <= n) {
            if (j == n) {
                if (zeroCount <= k) ans = max(ans, j - i);
                break;
            }

            if (a[j] == 1) {
                ++j;
            } else {
                if (zeroCount < k) {
                    ++zeroCount;
                    ++j;
                } else {
                    ans = max(ans, j - i);
                    if (i < j) {
                        if (a[i] == 0) --zeroCount;
                        ++i;
                    } else {
                        ++i;
                        ++j;
                    }
                }
            }
        }

        return ans;
    }
};
