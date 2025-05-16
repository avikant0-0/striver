class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        sort(a.begin(),a.end());    
        vector<int> ans;
        int n = a.size();
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(upper_bound(a.begin(),a.end(),a[i])-lower_bound(a.begin(),a.end(),a[i]) > n/3){
                    ans.push_back(a[i]);
                }
            }else if(a[i] != a[i-1]){
                if(upper_bound(a.begin(),a.end(),a[i])-lower_bound(a.begin(),a.end(),a[i]) > n/3){
                    ans.push_back(a[i]);
                }
            }
            
        }
        return ans;
    }
};