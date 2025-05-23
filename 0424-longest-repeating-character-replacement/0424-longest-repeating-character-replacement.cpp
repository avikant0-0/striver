class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0, i = 0, j = 0;
        char mx = '-';
        vector<int> hash(26);

        while( j < n ){
            hash[s[j]-'A']++;
            if(mx == '-' || hash[s[j]-'A'] > hash[mx-'A']){
                mx = s[j];
            }
            int len = j - i + 1;
            int damage = len - hash[mx-'A'];        

            // cout << mx <<" " << damage << " " << len << endl;
            int mxfreq = hash[mx-'A'];

            if(len - mxfreq > k){
                --len;
                hash[s[i]-'A']--;
                ++i;
            }
            ans = max(ans,len);
            ++j;
        }

        return ans;
    }
};