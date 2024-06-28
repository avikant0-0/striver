class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        string result;
        int n = s.size();
        for(char c : s){
            if(!st.empty() && st.top().first == c){
                st.top().second += 1; 
            }
            else {
                st.push({c,1});
            }
            if(st.top().second == k){
                st.pop();
            }
        }
        while(!st.empty()) {
            while(st.top().second > 0) {
                result.push_back(st.top().first);
                st.top().second--;
            }
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result ;
    }
};