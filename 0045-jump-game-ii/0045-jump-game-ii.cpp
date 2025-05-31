class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        set<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.insert({min(i+a[i],n-1),1});
                continue;
            }
            if(a[i] + i <= st.rbegin()->first) continue;
            
            int t = st.lower_bound({i,0})->second;
            st.insert({min(i+a[i],n-1),t+1});
        }
        return st.lower_bound({n-1,0})->second;
    }
};