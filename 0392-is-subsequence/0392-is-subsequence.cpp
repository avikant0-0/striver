class Solution {
public:
    int f(auto &s,auto &t,int m,int n){
        if(m < 0 || n < 0) return 0; 
        if(s[m]==t[n]) return  1 + f(s,t,m-1,n-1);
        else return  f(s,t,m,n-1);
    }
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        // if(m > n) return false;
        return f(s,t,m-1,n-1) == m; 
    }
};