class Solution {
public:
    string reverseWords(string s) {
        vector <string>  ans;
        int n = s.size();
        string temp = "";
        for(int i = 0; i < n; i++){
            
           if(s[i] == ' ') continue;
           string temp = "";
           while(s[i] != ' ' && i < n) temp += s[i],++i;
           ans.push_back(temp);

        }
        reverse(ans.begin(),ans.end());
        string a = "";
        for(int i = 0; i < ans.size(); i++){
            a += ans[i];
            if(i != ans.size() - 1) a += ' ';
        }
        return a; 
    }
};