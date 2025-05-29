class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c : s) mp[c]++;

        s.clear();
        vector<pair<char,int>> vp(mp.begin(),mp.end());
        sort(vp.begin(),vp.end(),[&](auto a,auto b){
            return a.second > b.second;
        });

        for(auto [l,r] : vp){
            for(int i = 0; i < r; i++){
                s += l;
            }
        }

        return s;
    }
};