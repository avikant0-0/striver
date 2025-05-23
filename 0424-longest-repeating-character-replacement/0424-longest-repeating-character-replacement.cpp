class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0, i = 0, j = 0;
        char mx = '-';
        vector<int> hash(26);

        while( j < n ){
            hash[s[j]-'A']++;
            if(mx == '-') mx = s[j];
            if(hash[s[j]-'A'] > hash[mx-'A']){
                mx = s[j];
            }
            int len = j - i + 1;
            int damage = len - hash[mx-'A'];        

            // cout << mx <<" " << damage << " " << len << endl;

            if(damage <= k){
                ans = max(ans,len);
                ++j;
            }else{
                hash[s[i]-'A']--;
                hash[s[j]-'A']--;
                int ind = max_element(hash.begin(),hash.end()) - hash.begin();
                mx = ('A' + ind);
                ++i;
            }
        }

        return ans;
    }
};