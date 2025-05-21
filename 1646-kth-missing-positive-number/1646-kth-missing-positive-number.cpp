class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        vector<int> m;
        for(int i = 1; i <= k + a.size(); i++){
            if(binary_search(a.begin(),a.end(),i)) continue;
            else m.push_back(i);
        }
        return m[k-1];
    }
};