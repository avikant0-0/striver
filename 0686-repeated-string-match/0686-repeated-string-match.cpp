class Solution {
public:
    int f(string a,string b){

        long long mod = 1e9+7;

        long long n = a.size(), m = b.size();
        if(n < m) return false;

        long long power = 1;
        for(long long i = 0; i < m - 1; i++) power = (power * 10) % mod;
        long long hash_b = 0,hash_a = 0;
        for(long long i = 0; i < m; i++) hash_b = ((10*hash_b) % mod + (b[i]-'a'+1) % mod) % mod;

        for(long long i = 0 ; i < n; i++){
            if(i < m - 1) {
                hash_a = ((10*hash_a) % mod + (a[i] - 'a' + 1) % mod) % mod;
                continue;
            }

            hash_a = ((10*hash_a) % mod + (a[i] - 'a' + 1) % mod) % mod;
            if(hash_a == hash_b) return true;
 
            hash_a = ((hash_a) % mod - (power * (a[i-m+1] - 'a' + 1) + mod) % mod) % mod;

        }

        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = ( b.length() + a.length() - 1 )/ a.length();

        string c = "";
        for(int i = 0; i < n  ; i++) c = c + a; 

        
        for(int i =0; i < 2; i++){
            if(f(c,b)){
                return n + i ; 
            }
            c = c + a;
        }
        return -1; 

    }
};