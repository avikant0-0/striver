class Solution {
public:
    void dfs(const vector<int>& nums, set<vector<int>>& st, int i, vector<int> res){
        if(i == nums.size()){
            st.insert(res);
            return;
        }
        
        res.push_back(nums[i]);
        dfs(nums,st,i+1,res);
        res.pop_back();
        dfs(nums,st,i+1,res); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st; 
        sort(nums.begin(),nums.end());
        
        dfs(nums,st,0,vector<int>());
        vector<vector<int>> answer(st.begin(),st.end());

        return answer;  
    }
};