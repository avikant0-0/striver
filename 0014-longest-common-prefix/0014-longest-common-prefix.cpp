class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int m = INT_MAX, n = s.size();
        for(int i = 0; i < n; i++) m = min(m,int(s[i].size()));

        string ans = "";
        // cout << m << endl;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(s[i][j] != s[0][j]) return ans;
            }
            ans += s[0][j];
        }
        return ans;
    }
};