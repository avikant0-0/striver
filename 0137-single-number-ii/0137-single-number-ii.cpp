class Solution {
public:
    int singleNumber(vector<int>& a) {
        int n = a.size();
        vector<int> o(32,0);

        for(int i : a)
        {
            for(int j = 0; j <= 31; j++)
            {
                int d = ((i>>j)&1);
                o[j] += d;
            }
        }

        int ans = 0;
        for(int j = 0; j <= 31; j++)
        {
            if(o[j] % 3 == 0)continue;
            ans = (ans | (1<<j));
        }
        return ans;
    }
};