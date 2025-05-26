class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int n = s.size();
        stack<char>st;
        for(int i = 0; i < n; i++){
            if(st.empty()) st.push('(');
            else if(s[i] == '(' && !st.empty()){
                st.push(s[i]);
                ans += s[i];
            }
            else if(s[i] == ')' && st.size() > 1){
                st.pop();
                ans += s[i];
            }else{
                st.pop();
            }
        }
        return ans;
    }
};