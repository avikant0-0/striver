class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int global = 0;
        sort(a.begin(),a.end());
        auto new_begin = unique(a.begin(),a.end());
        a.erase(new_begin,a.end());
        for(int i = 0; i < a.size(); i++){
            int local = 0;
            if(binary_search(a.begin(),a.end(),a[i]-1)) continue;
            for(int j = a[i];; j++){
                if(binary_search(a.begin(),a.end(),j)){
                    ++local;
                }else break;
            }
            global = max(global,local);
        }
        return global;
    }
};