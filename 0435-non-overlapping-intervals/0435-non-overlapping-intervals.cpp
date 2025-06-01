class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        vector<int> prev = {INT_MIN,INT_MIN};
        int ans = 0;
        sort(I.begin(),I.end(),[&](auto& a,auto& b){
            return a[1] < b[1];
        });
        for(int i = 0; i < I.size(); i++){
            if(I[i][0] >= prev[1]){
                prev = I[i];
                continue;
            }
            ++ans;
            continue;
        }
        return ans;
    }
};