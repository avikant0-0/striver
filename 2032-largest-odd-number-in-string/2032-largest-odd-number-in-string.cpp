class Solution {
public:
    string largestOddNumber(string s) {
        int j = s.size() - 1;
        while(j >= 0 && ((s[j] - '0') % 2 == 0)){
            --j;
        }
        return s.substr(0,j+1);
    }
};