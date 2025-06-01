class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for(int i = 0; i < n; i++){
            if(gas[i] >= cost[i]){
                // cout << i << endl;
                int ind = i, g = 0;

                for(int j = 0; j <= n; j++){
                    g += gas[ind];

                    if(ind == i && j != 0) return i;
                    if(g >= cost[ind]){
                        g -= cost[ind];
                        ++ind;
                        ind = (ind % n);
                        continue;
                    }
                    else {
                        if(ind >= i) i = ind;
                        else return -1;
                        break;
                    }
                }
            }
        }
        return -1;
    }
};