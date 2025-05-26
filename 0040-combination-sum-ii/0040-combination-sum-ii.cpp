class Solution {
public:
    void f(int ind,int sum,auto& a,auto& ans,auto& temp,int t){
        if(sum > t){
            return;
        }
        if(ind >= a.size()){
            if(sum == t) ans.push_back(temp);
            return;
        }
        temp.push_back(a[ind]);
        f(ind+1,sum+a[ind],a,ans,temp,t);
        temp.pop_back();

        int ind2 = upper_bound(a.begin(),a.end(),a[ind]) - a.begin();
        f(ind2,sum,a,ans,temp,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(a.begin(),a.end());
        f(0,0,a,ans,temp,t);

        return ans;
    }
};