class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            string sub = "";
            set<pair<int,char>> st;
            vector<int> hash(26,0);
            for(int j = i; j < n; j++){
                st.erase({hash[s[j]-'a'],s[j]});
                hash[s[j]-'a']++;
                st.insert({hash[s[j]-'a'],s[j]});
                ans += prev(st.end())->first - st.begin()->first;
            }
        }
        return ans;
    }
};