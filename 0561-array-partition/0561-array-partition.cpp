class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i = 0; i < a.size(); i+=2){
            ans += a[i];
        }
        return ans;
    }
};