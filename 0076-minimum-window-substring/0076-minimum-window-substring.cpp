class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        map<char,int> mpt;
        for(char c : t) mpt[c]++;
        
        map<char,int> mps;

        int i = 0, j = 0, start = 0, minLen = INT_MAX,cnt = 0;

        while( j < n ){
            if(mpt.find(s[j]) != mpt.end()){
                if(mps[s[j]] < mpt[s[j]]) ++cnt;
                mps[s[j]]++;
            }

            while(cnt >= t.size()){
                if(j - i + 1 < minLen && cnt == t.size()){
                    minLen = j - i + 1;
                    start = i;
                }
                if(mpt.find(s[i]) != mpt.end()){
                    if(mps[s[i]] <= mpt[s[i]]) --cnt;
                    mps[s[i]]--;
                }
                ++i;
            }

            

            ++j;
        }

        // cout << minLen << endl;
        return s.substr(start,minLen == INT_MAX ? 0 : minLen);
    }
};