class Solution {
public:
    void f(int ind,auto&a ,auto& ans,auto& temp){
        if(ind == a.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(a[ind]);
        f(ind+1,a,ans,temp);
        temp.pop_back();

        f(ind+1,a,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,a,ans,temp);
        return ans;
    }
};