class Solution {
public:
    void dfs(int i,vector<int> tempans, int target, vector<int>&a, vector<vector<int>>& st){
        
        if(target == 0) st.push_back(tempans);
        if(i >= a.size()) return; 

        if(target >= a[i] && i < a.size()){
            tempans.push_back(a[i]);
            dfs(i,tempans,target-a[i],a,st);
            tempans.pop_back();
            dfs(i+1,tempans,target,a,st); 
        }else return; 
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> st;
        int n = a.size();
        sort(a.begin(),a.end());

        dfs(0,vector<int>(),target,a,st);
        return st; 
    }
};