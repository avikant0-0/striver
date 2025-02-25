class Solution {
public:
    void dfs(const vector<int>& nums, vector<vector<int>>& st, int i, vector<int> res){
        if(i == nums.size()){
            st.push_back(res);
            return;
        }
        
        res.push_back(nums[i]);
        dfs(nums,st,i+1,res);
        res.pop_back();

        int ub = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();

        dfs(nums,st,ub,res); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> st; 
        sort(nums.begin(),nums.end());
        
        dfs(nums,st,0,vector<int>());
        return st;  
    }
};