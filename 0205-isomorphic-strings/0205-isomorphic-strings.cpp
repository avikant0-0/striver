class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        vector<int> assigned(255,0);
        for(int i = 0; i < s.size(); i++){
            if(mp.find(t[i]) == mp.end()){
                if(assigned[s[i]] == 1) return false;
                assigned[s[i]] = 1;
                mp[t[i]] = s[i];
                continue;
            }
            else{
                if(mp[t[i]] == s[i]) continue;
                else return false;
            }
        }

        return true;
    }
};