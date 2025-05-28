class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        string ans;
        for(int j = 0; j < a[0].size(); j++){
            char c = '-';
            for(int i = 0; i < a.size(); i++){
                if(j >= a[i].size()){
                    c = '-';
                    break;
                }

                if(c == '-') c = a[i][j];
                else if(a[i][j] != c) {
                    c = '-';
                    break;
                }
            }
            if(c != '-') ans.push_back(c);
            else break;
        }
        return ans;
    }
};