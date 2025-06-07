class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i <= 31; i++)
        {
            int d1 = ((start>>i) & 1);
            int d2 = ((goal >>i) & 1);

            if(d1 == d2) continue;
            else ++ans;
        }
        return ans;
    }
};