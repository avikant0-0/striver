class Solution {
public:
    int f(const string& a,int k){
        if(k < 0) return 0;

        int ans = 0,i = 0, j = 0,dc = 0,n = a.size();
        vector<int> hash(3,0);

        while( j < n ){
            if(hash[a[j]-'a'] == 0) ++dc;

            hash[a[j]-'a']++;
            
            while( dc > k ){
                hash[a[i]-'a']--;
                if(hash[a[i]-'a'] == 0) --dc;
                ++i;
            }

            ans += j - i + 1;
            ++j;
        }

        return ans;
    }
    int numberOfSubstrings(const string& s) {
        return f(s,3) - f(s,2);
    }
};