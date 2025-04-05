class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        string s_ans ;
        s_ans += s[0];
        for(int i = 0; i < n ; i++){
            int len = 1, l = i - 1, r = i + 1;
            string temp = "";
            temp += s[i];
            while(l >= 0 && r < n && s[l] == s[r]){
                temp.push_back(s[r]);
                temp.insert(temp.begin(),s[l]);
                --l,++r,len++;
            }
            if(len > ans){
                ans = len;
                s_ans = temp;
            }
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i] != s[i+1]) continue;
            int len = 2,l = i - 1, r = i + 2;
            string temp = "";
            temp += s[i];
            temp += s[i+1];
            while(l >= 0 && r < n && s[l] == s[r]){
                temp.push_back(s[r]);
                temp.insert(temp.begin(),s[l]);
                --l,++r,len++;
            }
            if(len > ans){
                ans = len;
                s_ans = temp;
            }
        }
        return s_ans;
    }
};