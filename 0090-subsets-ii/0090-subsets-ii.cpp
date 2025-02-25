class Solution {
public:
    void dfs(const vector<int>& nums, vector<vector<int>>& st, int i, vector<int> res){
        if(i == nums.size()){
            st.push_back(res);
            return;
        }

        int ind = upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();

        for(int j = i; j < ind; j++){
            for(int k = 0; k < ind - j ; k++){
                res.push_back(nums[i]);
            }
            dfs(nums,st,ind,res);
            for(int k = 0; k < ind - j ; k++){
                res.pop_back(); 
            }
        }

        dfs(nums,st,ind,res); 

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> st; 
        sort(nums.begin(),nums.end());
        
        dfs(nums,st,0,vector<int>());
        return st;  
    }
};