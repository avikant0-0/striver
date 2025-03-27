class Solution {
public:

    bool isP(const auto& s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] == s[j]){
                ++i;
                --j;
                continue;
            }
            else return false;
        }

        return true; 
    }

    void dfs(int ind,auto& s,auto& r,auto t){
        int n = s.size();
        if(ind == n){
            r.push_back(t);
            return;
        }

        for(int i = ind; i < n; i++){
            if(isP(s.substr(ind,i -ind+1))){
                t.push_back(s.substr(ind,i-ind+1));
                dfs(i+1,s,r,t);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        dfs(0,s,r,vector<string> ());
        return r;
    }
};