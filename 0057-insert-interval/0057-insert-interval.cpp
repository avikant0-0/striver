class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& i, vector<int>& ni) {
        int n = i.size();
        if(n == 0) return {ni};

        for(int j = 0; j <= n; j++){
            if(j == n) i.insert(i.begin()+j,ni);
            
            if(i[j][0] > ni[0]){
                i.insert(i.begin()+j,ni);
                break;
            }
        }
        vector<vector<int>> I = {{i[0][0],i[0][1]}};
        for(int j = 1; j < i.size(); j++){
            if(i[j][0] > I.back()[1]){
                I.push_back(i[j]);
            }
            else{
                I.back()[1] = max(I.back()[1],i[j][1]);
            }
        }
        return I;
    }
};