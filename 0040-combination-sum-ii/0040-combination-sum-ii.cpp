class Solution {
public:
    void dfs(int ind,int target,auto& A,auto& r,auto t){
        int n = A.size();
        if(ind == -1 ){
            if(target == 0) r.push_back(t);
            return;
        }

        //take
        if(A[ind]<=target){
            t.push_back(A[ind]);
            dfs(ind-1,target - A[ind],A,r,t);
            t.pop_back();
        }
        
        //nottake
        int lb = lower_bound(A.begin(),A.end(),A[ind])-A.begin();
        dfs(lb-1,target,A,r,t);

    }
    vector<vector<int>> combinationSum2(vector<int>& A, int T) {
        sort(A.begin(),A.end());
        vector<vector<int>> r; 
        dfs(A.size()-1,T,A,r,vector<int>());

        return r;
    }
};