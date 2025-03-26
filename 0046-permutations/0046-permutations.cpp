class Solution {
public:
    void dfs(int ind, auto& permutations,auto nums){
        if(ind == nums.size()){
            permutations.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            swap(nums[i],nums[ind]);
            dfs(ind+1,permutations,nums);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        dfs(0,permutations,nums);
        return permutations;
    }
};