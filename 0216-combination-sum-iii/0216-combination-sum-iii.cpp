class Solution {
public:
    void f(int ind,int sum,auto& a,auto& ans,auto& temp,int k,int n){
        if(sum > n || temp.size() > k){
            return;
        }
        if(ind == a.size()){
            if(sum == n && temp.size() == k) ans.push_back(temp);
            return;
        }

        temp.push_back(a[ind]);
        f(ind+1,sum+a[ind],a,ans,temp,k,n);
        temp.pop_back();

        f(ind+1,sum,a,ans,temp,k,n);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,0,a,ans,temp,k,n);
        return ans;
    }
};