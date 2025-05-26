class Solution {
public:

    bool isP(auto& str){
        int i = 0, j = str.size() - 1;
        while( i < j ){
            if(str[i] != str[j]) return false;
            ++i;--j;
        }
        return true;
    }
    void f(int ind,auto& s,auto temp,auto& ans){
        int n = s.size();
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < n;i++){
            string sub = s.substr(ind,i-ind+1);
            if(isP(sub)){
                temp.push_back(sub);
                f(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0,s,temp,ans);
        return ans;
    }
};