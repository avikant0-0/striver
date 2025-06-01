class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            char c1 = s[i] , c2 = s[j];
            if(s[i] <= 'z' && s[i] >= 'a') c1 = s[i] - 32;
            if(s[j] <= 'z' && s[j] >= 'a') c2 = s[j] - 32;

            // cout << c1 <<" " << c2 << endl;

            if( !(c1 <= 'Z' && c1 >= 'A') && !(c1>='0' && c1 <= '9')){
                ++i;
                continue;
            }
            if( !(c2 <= 'Z' && c2 >= 'A') && !(c2>='0' && c2 <= '9')){
                --j;
                continue;
            }
            if(c1 != c2 ) return false;
            ++i;
            --j;
        }
        return true;

    }
};