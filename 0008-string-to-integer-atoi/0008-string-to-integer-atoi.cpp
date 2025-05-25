class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i] == ' ') ++i;

        int sign;
        if(s[i] == '-') sign = -1,++i;
        else if(s[i] == '+') sign = 1,++i;
        else sign = 1;

        long long ans = 0;
        while( s[i] <= '9' && s[i] >= '0'){
            ans = ans*10 + (s[i]-'0');
            if(ans >= INT_MAX) break;
            ++i;
        }

        ans *= sign;

        if(ans >= INT_MAX) return INT_MAX;
        else if(ans <= INT_MIN) return INT_MIN;
        else return int(ans);
    }
};