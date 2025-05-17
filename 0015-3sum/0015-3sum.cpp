class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());    

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i != 0 && a[i-1] == a[i]){
                continue;
            }

            int j = i + 1;
            
            int k = n - 1;
            

            while(j < k){

               

                if(a[j] + a[k] < -a[i]) ++j;
                else if(a[j] + a[k] > -a[i]) --k;
                else {
                    ans.push_back({a[i],a[j],a[k]});
                    ++j;
                    --k;
                    
                    while(j < k && a[j] == a[j-1]){
                        ++j;
                    }

                    while( k > j && a[k] == a[k+1]){
                        --k;
                    }

                }
            } 

        }

        return ans;
    }
};