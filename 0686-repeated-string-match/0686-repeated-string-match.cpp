class Solution {
public:
    int f(string a,string b){
        int n = a.size(), m = b.size();
        if(n < m) return false;

        for(int i = 0; i <= n - m; i++){
            if(a.substr(i,m) == b) return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.size(),m = b.size();
        int r = m/n + (r*n <= m);
        
        string t = a;
        for(int i = 0; i <= r; i++){
            if(f(a,b)) return i+1;
            a += t;
        }
        
        return -1; 
    }
};