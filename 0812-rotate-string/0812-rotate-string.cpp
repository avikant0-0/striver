class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.size() != g.size()) return false;
        for(int k = 0; k < s.size(); k++){
            if(s[k] != g[0]) continue;
            int i = k;
            for(int j = 0; j < s.size(); j++){
                if(s[i] == g[j]){
                    if(j == s.size() - 1){
                        return true;
                    }
                    i = ( i + 1 ) % s.size();
                    continue;
                }else break;
            }
        }

        return false;
    }
};