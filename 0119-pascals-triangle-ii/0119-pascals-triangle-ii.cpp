class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> prev,curr;
        for(int i = 0; i <= n;i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i) curr.push_back(1);
                else curr.push_back(prev[j]+prev[j-1]);
            }
            prev = curr;
            if(i != n) curr.clear();
        }
        return curr;
    }
};