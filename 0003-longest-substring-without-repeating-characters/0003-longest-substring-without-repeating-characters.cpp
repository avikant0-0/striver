class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,0);
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;
        while(j <= n){
            if( j == n ) {
                ans = max(ans,j-i);
                break;
            }
            if(hash[s[j]] == 0){
                hash[s[j]] = 1;
                ++j;
            }else{
                ans = max(ans,j-i);
                hash[s[i]] = 0;
                ++i;
            }
        }
        return ans;
    }
};