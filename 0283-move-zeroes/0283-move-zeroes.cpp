class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 0;
        while(j < n){
            if(a[j] == 0){
                ++j;
                continue;
            }else{
                a[i] = a[j];
                ++i,++j;
            }
        }
        while(i < n) a[i] = 0,++i;
    }
};