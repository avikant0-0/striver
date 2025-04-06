class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') ++i;
        int sign = 1;

        if(s[i] == '+') sign = 1, ++i;
        else if(s[i] == '-') sign = -1, ++i;

        long res = 0;

        while(i < n){
            if(s[i] > '9' || s[i] < '0') break;
            if(res > INT_MAX/10) return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (s[i] - '0');
            ++i;
        }


        if(res*sign >= INT_MAX) return INT_MAX;
        else if(res*sign <= INT_MIN) return INT_MIN; 
        return res*sign;
    }
};