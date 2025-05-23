class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        int ans = 0;
        map<int,int> mp;

        while(j < n){
            mp[a[j]]++;

            if(mp.size() <= 2){
                ans = max(ans,j-i+1);
                ++j;
            }
            else{
                while(mp.size() > 2){
                    mp[a[i]]--;
                    if(mp[a[i]] == 0) mp.erase(a[i]);
                    ++i;
                }
                ans = max(ans,j-i+1);
                ++j;
            }
        }

        return ans;
    }
};