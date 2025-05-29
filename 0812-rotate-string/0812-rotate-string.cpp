class Solution {
public:
    bool rotateString(string s, string g) {
        if(s.size() != g.size()) return false;

        for(int i = 1; i <= s.size(); i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s == g) return true;
        }

        return false;
    }
};