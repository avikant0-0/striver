class Solution {
public:
    void f(int open,int close,int n,auto& temp,auto& ans){
        if(close > open || open > n || close > n) return;

        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back('(');
        f(open+1,close,n,temp,ans);
        temp.pop_back();

        temp.push_back(')');
        f(open,close+1,n,temp,ans);
        temp.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        f(0,0,n,temp,ans);
        return ans;
    }
};