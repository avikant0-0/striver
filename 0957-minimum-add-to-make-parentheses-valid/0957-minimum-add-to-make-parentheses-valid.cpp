class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int opening = 0, ending = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') {
                st.push('(');
                ++opening; 
            }
            else if(s[i] == ')' && !st.empty()){
                st.pop(); 
                --opening;
            }
            else ++ending; 
        }

        return opening + ending ;
    }
};