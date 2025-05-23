class Solution {
public:
    int totalFruit(vector<int>& a) {
        int n = a.size();
        set<int> type;
        int i = 0, j = 0;
        int ans = 0;
        map<int,int> mp;

        while(j < n){
            type.insert(a[j]);
            mp[a[j]]++;

            if(type.size() <= 2){
                ans = max(ans,j-i+1);
                ++j;
            }
            else{
                while(type.size() > 2){
                    mp[a[i]]--;
                    if(mp[a[i]] == 0) type.erase(a[i]);
                    ++i;
                }
                ans = max(ans,j-i+1);
                ++j;
            }
        }

        return ans;
    }
};