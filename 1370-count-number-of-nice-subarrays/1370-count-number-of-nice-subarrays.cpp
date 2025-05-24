class Solution {
public:
    int f(vector<int>& a, int k){
        if(k < 0) return 0;

        int n = a.size(), i = 0, j = 0, ans = 0, odd = 0;

        while( j < n ){
            odd += (a[j] % 2);

            while(odd > k){
                odd -= (a[i]%2);
                ++i;
            }

            ans += j - i;
            ans += (a[j] % 2);

            ++j;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& a, int k) {
        return f(a,k) - f(a,k-1);
    }
};