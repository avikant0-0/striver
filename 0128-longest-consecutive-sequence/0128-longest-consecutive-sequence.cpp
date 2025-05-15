class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int global = 0;
        unordered_set<int>st(a.begin(),a.end());

        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int local = 0;   
                int j = it;
                while(st.find(j) != st.end()){
                    ++local;
                    ++j;
                }
                global = max(global,local);
            }
            
        }
        return global;
    }
};