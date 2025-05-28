class Solution {
public:
    void skipspace(int& i,auto& s){
        while(i <= s.size() ){
            if(i == s.size()) break;
            else if(s[i] == ' ') ++i;
            else break;
        }
    }
    void addreverseword(int& i,auto& s,auto& ans){ 
        int ini = i;

        while(i < s.size() && s[i] != ' '){
            ++i;
        }
        for(int j = i - 1; j >= ini; j--){
            ans.push_back(s[j]);
        }
        ans.push_back(' ');

    }
    string reverseWords(string s) {
        int i = 0;
        string ans;
        while(i < s.size()){
            skipspace(i,s);
            if(i < s.size()) addreverseword(i,s,ans);
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};