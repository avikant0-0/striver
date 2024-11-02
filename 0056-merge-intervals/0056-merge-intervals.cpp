class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        intervals.push_back({INT_MAX,INT_MAX});

        vector<vector<int>> ans ;
        int l = intervals[0][0] ; 
        int r = intervals[0][1] ;
        for(int i = 1; i <= n; i++){
            if(intervals[i][0] <= r) {
                r =  max(r,intervals[i][1]); 
            }
            else{
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        return ans ;
    }
};