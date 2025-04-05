class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ') continue;
            if(i + 1 < s.size() && s[i] == s[i+1]) {
                s.erase(s.begin()+i);
                --i;
                continue;
            }
        }
        if(s[0] == ' ') s.erase(s.begin());
        if(s[s.size()-1] == ' ') s.erase(s.end()-1);

        reverse(s.begin(),s.end());
        int n = s.size();

        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && s[j] != ' ') ++j;
            reverse(s.begin()+i,s.begin()+j);
            i = j;
        }
        return s; 
    }
};