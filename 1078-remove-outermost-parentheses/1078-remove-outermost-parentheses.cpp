class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size(),open = 0;
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') ++open;
            else --open;
            
            if(open == 1 && s[i] == '(') continue;
            if(open == 0) continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};