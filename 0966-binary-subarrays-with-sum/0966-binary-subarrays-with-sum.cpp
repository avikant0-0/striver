class Solution {
public:
    int f(int g,vector<int>& a){
        if(g < 0) return 0;
        int n = a.size(), i = 0, j = 0;
        int sum = 0, ans = 0;
        while(j < n){
            sum += a[j];

            while(sum > g){
                sum -= a[i];
                ++i;
            }

            ans += j - i + 1;
            ++j;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& a, int g) {
        int n = a.size();
        return f(g,a) - f(g-1,a);
    }
};