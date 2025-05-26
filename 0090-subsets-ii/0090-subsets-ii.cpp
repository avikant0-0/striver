class Solution {
public:
    void f(int ind,auto& a,auto& temp,auto& ans){

        if(ind == a.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i <= a.size(); i++){
            if(i == a.size()){
                f(i,a,temp,ans);
            }
            else if(i == ind || (a[i] != a[i-1])){
                temp.push_back(a[i]);
                f(i+1,a,temp,ans);
                temp.pop_back();
            }
            
        }
    }   
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(a.begin(),a.end());
        f(0,a,temp,ans);
        return ans;
    }
};